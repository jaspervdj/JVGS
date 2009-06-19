#include "Renderer.h"
#include "VideoManager.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include "../math/MathManager.h"
using namespace jvgs::math;

#include <iostream>
#include <cmath>

namespace jvgs
{
    namespace video
    {
        void Renderer::beginConcavePolygon()
        {
        }

        void Renderer::endConcavePolygon()
        {
            if(!concavePolygonTopLeft) {
                LogManager::getInstance()->warning("Drawing empty polygon...");
                return;
            }

            VideoManager *videoManager = VideoManager::getInstance();
            Color color = videoManager->getColor();

            /* Draw to stencil. */
            glDisable (GL_BLEND);
            glEnable (GL_STENCIL_TEST);
            glStencilMask (0x01);
            glStencilOp (GL_KEEP, GL_KEEP, GL_INVERT);
            glStencilFunc (GL_ALWAYS, 0, ~0);
            glColorMask (GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);

            glColor4f (1.0, 1.0, 1.0, 1.0);
            glBegin (GL_TRIANGLE_FAN);
            /* To figure out: will this always work? */
            glVertex2f(concavePolygonTopLeft->getX(),
                    concavePolygonTopLeft->getY());

            for(std::vector<Vector2D>::iterator iterator =
                    concavePolygonList.begin();
                    iterator != concavePolygonList.end(); iterator++) {
                glVertex2f((*iterator).getX(), (*iterator).getY());
            }
            glEnd();

            glColorMask (GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            glStencilFunc (GL_EQUAL, 0x00, 0x01);
            glStencilOp (GL_KEEP, GL_KEEP, GL_KEEP);

            videoManager->setColor(color);
            glBegin (GL_LINES);
            for(std::vector<Vector2D>::iterator iterator =
                    concavePolygonList.begin();
                    iterator != concavePolygonList.end(); iterator++) {
                glVertex2f((*iterator).getX(), (*iterator).getY());
            }
            glEnd ();

            glStencilFunc (GL_EQUAL, 0x01, 0x01);
            glStencilOp (GL_ZERO, GL_ZERO, GL_ZERO);

            videoManager->setVideoDefaults();
            videoManager->setColor(color);

            glBegin (GL_QUADS);
            glVertex2f(concavePolygonTopLeft->getX(),
                    concavePolygonTopLeft->getY());
            glVertex2f(concavePolygonTopLeft->getX(),
                    concavePolygonBottomRight->getY());
            glVertex2f(concavePolygonBottomRight->getX(),
                    concavePolygonBottomRight->getY());
            glVertex2f(concavePolygonBottomRight->getX(),
                    concavePolygonTopLeft->getY());
            glEnd ();

            glDisable (GL_STENCIL_TEST);

            delete concavePolygonTopLeft;
            delete concavePolygonBottomRight;
            concavePolygonTopLeft = concavePolygonBottomRight = 0;

            concavePolygonList.clear();
        }

        Renderer::Renderer()
        {
            busy = false;
            concavePolygonTopLeft = 0;
            concavePolygonBottomRight = 0;
        }

        Renderer::~Renderer()
        {
        }

        void Renderer::begin(Type type)
        {
            busy = true;
            rendering = type;
            if(rendering == CONCAVE_POLYGON)
                beginConcavePolygon();
            else
                glBegin(type);
        }

        void Renderer::end()
        {
            busy = false;
            if(rendering == CONCAVE_POLYGON)
                endConcavePolygon();
            else
                glEnd();
        }

        bool Renderer::isBusy() const
        {
            return busy;
        }

        void Renderer::vector(const Vector2D &vector)
        {
            /* Regular. */
            if(rendering != CONCAVE_POLYGON) {
                glVertex2f(vector.getX(), vector.getY());

            /* We need to determine the max span area. */
            } else {
                concavePolygonList.push_back(Vector2D(vector));
                /* First vector. */
                if(!concavePolygonTopLeft) {
                    concavePolygonTopLeft = new Vector2D(vector);
                    concavePolygonBottomRight = new Vector2D(vector);
                } else {
                    if(vector.getX() < concavePolygonTopLeft->getX())
                        concavePolygonTopLeft->setX(vector.getX());
                    if(vector.getX() > concavePolygonBottomRight->getX())
                        concavePolygonBottomRight->setX(vector.getX());
                    if(vector.getY() < concavePolygonTopLeft->getY())
                        concavePolygonTopLeft->setY(vector.getY());
                    if(vector.getY() > concavePolygonBottomRight->getY())
                        concavePolygonBottomRight->setY(vector.getY());
                }
            }
        }
    };
};
