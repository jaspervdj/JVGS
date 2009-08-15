#include "Font.h"

#include "../core/LogManager.h"
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

namespace jvgs
{
    namespace font
    {
        Font::Font(const string &fileName, float size)
        {
            this->size = size;

            matrix = AffineTransformationMatrix();
            matrix.scale(Vector2D(1.0f / 64.0f, 1.0f / 64.0f));
            matrix.scale(Vector2D(1.0f, -1.0f));

            LogManager *logManager = LogManager::getInstance();

            /* Create the main library and init it. */
            FT_Library library;
            if(FT_Init_FreeType(&library))
                logManager->error("Could not create main FreeType library.");
        
            /* Load the actual font. */
            FT_Face face;
            if(FT_New_Face(library, fileName.c_str(), 0, &face))
                logManager->error("Could not open '%s'.", fileName.c_str());

            /* Set the pixel size. */
            FT_Set_Pixel_Sizes(face, 0, (FT_UInt) size);

            /* Load a character. */
            FT_UInt index = FT_Get_Char_Index(face, 'd');
            FT_Load_Glyph(face, index, FT_LOAD_DEFAULT);

            FT_Outline outline = face->glyph->outline;
            Sketch *sketch = createSketch(&outline);
            sketch->render();
            delete sketch;

            FT_Done_Face(face);
            FT_Done_FreeType(library);
        }

        Font::~Font()
        {
            //delete sketch;
        }

        Sketch *Font::createSketch(FT_Outline *outline)
        {
            Sketch *sketch = new Sketch(Vector2D(16, 16));
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

                if(cubicPoints.size() == 2 && onPoints.size() == 2) {
                    CubicCurve *curve = new CubicCurve(onPoints[0],
                            cubicPoints[0], cubicPoints[1], onPoints[1]);
                    component->addSegment(curve);
                    cubicPoints.clear();
                    onPoints.erase(onPoints.begin());
                }

                if(quadraticPoints.size() == 2 && onPoints.size() < 2) {
                    Vector2D middle = quadraticPoints[0] + quadraticPoints[1];
                    middle *= 0.5f;
                    onPoints.push_back(middle);
                }

                while(quadraticPoints.size() >= 1 && onPoints.size() >= 2) {
                    QuadraticCurve *curve = new QuadraticCurve(onPoints[0],
                            quadraticPoints[0], onPoints[1]);
                    component->addSegment(curve);
                    quadraticPoints.erase(quadraticPoints.begin());
                    onPoints.erase(onPoints.begin());
                }

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
            sketch->setRoot(root);

            return sketch;
        }

        Vector2D Font::toVector(const FT_Vector &point) const
        {
            return matrix * Vector2D(point.x, point.y);
        }
    }
}
