#include "Renderer.h"
#include "VideoManager.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include "../math/MathManager.h"
using namespace jvgs::math;

#include <iostream>
#include <cmath>
using namespace std;

namespace jvgs
{
    namespace video
    {
        void Renderer::beginConcavePolygon()
        {
            if(!concavePolygonList)
                concavePolygonList = glGenLists(1);
            glNewList(concavePolygonList, GL_COMPILE);
        }

        void Renderer::endConcavePolygon()
        {
            glEndList();

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
            glVertex3f (0, 0, 0);
            glCallList(concavePolygonList);
            glEnd();

            glStencilFunc (GL_EQUAL, 0x01, 0x01);
            glStencilOp (GL_ZERO, GL_ZERO, GL_ZERO);

            glColorMask (GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
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
        }

        Renderer::Renderer()
        {
            busy = false;
            concavePolygonList = 0;
            concavePolygonTopLeft = 0;
            concavePolygonBottomRight = 0;
        }

        Renderer::~Renderer()
        {
            if(concavePolygonList)
                glDeleteLists(concavePolygonList, 1);
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
            glVertex2f(vector.getX(), vector.getY());

            /* We need to determine the max span area. */
            if(rendering == CONCAVE_POLYGON) {

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
