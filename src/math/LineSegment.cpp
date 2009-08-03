#include "LineSegment.h"
#include "BoundingBox.h"

#include <iostream>
using namespace std;

namespace jvgs
{
    namespace math
    {
        LineSegment::LineSegment(const Vector2D &start, const Vector2D &end)
        {
            this->start = start;
            this->end = end;
            boundingBox = 0;
        }

        LineSegment::~LineSegment()
        {
            if(boundingBox)
                delete boundingBox;
        }

        const Vector2D &LineSegment::getStart() const
        {
            return start;
        }

        const Vector2D &LineSegment::getEnd() const
        {
            return end;
        }

        Line LineSegment::getLine() const
        {
            return Line(start, end - start);
        }

        float LineSegment::getLength() const
        {
            return start.getDistance(end);
        }

        Vector2D LineSegment::getPoint(float t) const
        {
            return start * (1.0f - t) + end * t;
        }

        BoundingBox *LineSegment::getBoundingBox()
        {
            if(!boundingBox) {
                /* Calculate the segment bounding box x. */
                float minX, maxX, minY, maxY;
                if(start.getX() < end.getX()) {
                    minX = start.getX();
                    maxX = end.getX();
                } else {
                    minX = end.getX();
                    maxX = start.getX();
                }

                /* Calculate the segment bounding box x. */
                if(start.getY() < end.getY()) {
                    minY = start.getY();
                    maxY = end.getY();
                } else {
                    minY = end.getY();
                    maxY = start.getY();
                }

                boundingBox = new BoundingBox(Vector2D(minX, minY),
                        Vector2D(maxX, maxY));
            }

            return boundingBox;
        }
    }
}
