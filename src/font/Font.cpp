#include "Font.h"

#include "../core/LogManager.h"
#include "../core/DataManager.h"
using namespace jvgs::core;

#include "../sketch/Group.h"
#include "../sketch/Path.h"
#include "../sketch/PathComponent.h"
using namespace jvgs::sketch;

#include "../math/CubicCurve.h"
#include "../math/LineSegment.h"
#include "../math/QuadraticCurve.h"
using namespace jvgs::math;

#include <vector>
using namespace std;

#include "../video/VideoManager.h"
#include "../video/SketchyRenderer.h"
using namespace jvgs::video;

namespace jvgs
{
    namespace font
    {
        const int Font::NUMBER_OF_CHARACTERS = 256;

        Font::Font(const string &fileName, float size)
        {
            /* Some references. */
            ListManager *listManager = ListManager::getInstance();
            VideoManager *videoManager = VideoManager::getInstance();
            LogManager *logManager = LogManager::getInstance();
            DataManager *dataManager = DataManager::getInstance();

            advances = new float[NUMBER_OF_CHARACTERS];

            this->size = size;

            /* Matrix to convert points. */
            matrix = AffineTransformationMatrix();
            matrix.scale(Vector2D(1.0f / 64.0f, 1.0f / 64.0f));
            matrix.scale(Vector2D(1.0f, -1.0f));

            /* Generate lists. */
            base = listManager->createLists(NUMBER_OF_CHARACTERS);

            /* Create the main library and init it. */
            FT_Library library;
            if(FT_Init_FreeType(&library))
                logManager->error("Could not create main FreeType library.");
        
            /* Load the actual font. */
            FT_Face face;
            string expanded = dataManager->expand(fileName);
            if(FT_New_Face(library, expanded.c_str(), 0, &face))
                logManager->error("Could not open '%s'.", fileName.c_str());

            /* Set the pixel size. */
            FT_Set_Pixel_Sizes(face, 0, (FT_UInt) size);

            /* Load characters. */
            for(int i = 0; i < NUMBER_OF_CHARACTERS; i++) {

                /* Get the glyph. */
                FT_UInt index = FT_Get_Char_Index(face, i);
                FT_Load_Glyph(face, index, FT_LOAD_DEFAULT);
                FT_GlyphSlot glyph = face->glyph;

                /* Create the outline. */
                FT_Outline outline = glyph->outline;
                Group *group = createSketchGroup(&outline);

                /* Start rendering. */
                listManager->beginList(base + i);

                Renderer *renderer = new SketchyRenderer();
                group->render(renderer);
                delete renderer;
                delete group;

                /* Advance for next character. */
                Vector2D advance = toVector(glyph->advance);
                videoManager->translate(advance);
                advances[i] = advance.getX();

                /* End render. */
                listManager->endList();
            }

            /* Clean up. */
            FT_Done_Face(face);
            FT_Done_FreeType(library);
        }

        Font::~Font()
        {
            ListManager::getInstance()->deleteLists(base, NUMBER_OF_CHARACTERS);
            delete[] advances;
        }

        void Font::drawString(const string &string) const
        {
            VideoManager::getInstance()->push();
            ListManager *listManager = ListManager::getInstance();
            listManager->callLists(base, (GLubyte*) string.c_str(),
                    (int) string.size());
            VideoManager::getInstance()->pop();
        }

        float Font::getStringWidth(const string &string) const
        {
            float width = 0;

            for(string::size_type i = 0; i < string.size(); i++)
                width += advances[string[i]];

            return width;
        }

        Group *Font::createSketchGroup(FT_Outline *outline) const
        {
            Group *root = new Group(0);
            Path *path = new Path(root);
            PathComponent *component = new PathComponent(path);

            vector<Vector2D> onPoints;
            vector<Vector2D> quadraticPoints;
            vector<Vector2D> cubicPoints;

            /* Countour and point index. */
            int c = 0, p = 0;
            while(c < outline->n_contours && p < outline->n_points) {

                /* Add point. */
                Vector2D point = toVector(outline->points[p]);
                if(FT_CURVE_TAG(outline->tags[p]) == FT_CURVE_TAG_ON)
                    onPoints.push_back(point);
                else if(FT_CURVE_TAG(outline->tags[p]) == FT_CURVE_TAG_CONIC)
                    quadraticPoints.push_back(point);
                else if(FT_CURVE_TAG(outline->tags[p]) == FT_CURVE_TAG_CUBIC)
                    cubicPoints.push_back(point);

                /* A cubic curve matches. */
                if(cubicPoints.size() == 2 && onPoints.size() == 2) {
                    CubicCurve *curve = new CubicCurve(onPoints[0],
                            cubicPoints[0], cubicPoints[1], onPoints[1]);
                    component->addSegment(curve);
                    cubicPoints.clear();
                    onPoints.erase(onPoints.begin());
                }

                /* Insert "off" points. See freetype documentation. */
                if(quadraticPoints.size() == 2 && onPoints.size() < 2) {
                    Vector2D middle = quadraticPoints[0] + quadraticPoints[1];
                    middle *= 0.5f;
                    onPoints.push_back(middle);
                }

                /* Quadratic curve matches. Could be more than one. */
                while(quadraticPoints.size() >= 1 && onPoints.size() >= 2) {
                    QuadraticCurve *curve = new QuadraticCurve(onPoints[0],
                            quadraticPoints[0], onPoints[1]);
                    component->addSegment(curve);
                    quadraticPoints.erase(quadraticPoints.begin());
                    onPoints.erase(onPoints.begin());
                }

                /* Straight line segment matches. */
                if(onPoints.size() == 2 && quadraticPoints.size() <= 0 && 
                        cubicPoints.size() <= 0) {
                    LineSegment *segment = new LineSegment(onPoints[0],
                            onPoints[1]);
                    component->addSegment(segment);
                    onPoints.erase(onPoints.begin());
                }

                /* End of a contour. */
                if(p == outline->contours[c]) {
                    onPoints.clear();
                    quadraticPoints.clear();
                    cubicPoints.clear();
                    component->close();
                    path->addComponent(component);
                    component = new PathComponent(path);
                    c++;
                }

                p++;
            }

            component->close();
            path->addComponent(component);
            root->addSketchElement(path);

            return root;
        }

        Vector2D Font::toVector(const FT_Vector &point) const
        {
            return matrix * Vector2D((float) point.x, (float) point.y);
        }
    }
}
