#ifndef JVGS_SKETCH_PATHRENDERER_H
#define JVGS_SKETCH_PATHRENDERER_H

#include "PrimitiveRenderer.h"
#include "../math/Vector2D.h"
#include <map>

namespace jvgs
{
    namespace sketch
    {
        class Path;
        class PathSegment;
        class PathSegmentRenderer;

        class PathRenderer: public PrimitiveRenderer
        {
            private:
                Path *path;
                PathSegment *lastSegment;
                math::Vector2D startingPoint;
                math::Vector2D currentPoint;
                math::Vector2D lastControlPoint;
                std::map<char, PathSegmentRenderer*> segmentRenderers;

            public:
                PathRenderer(Path *path);
                virtual ~PathRenderer();

                virtual PathSegment *getLastSegment() const;

                virtual const math::Vector2D &getStartingPoint() const;
                virtual void setStartingPoint(const math::Vector2D &point);

                virtual const math::Vector2D &getCurrentPoint() const;
                virtual void setCurrentPoint(const math::Vector2D &point);

                virtual const math::Vector2D &getLastControlPoint() const;
                virtual void setLastControlPoint(const math::Vector2D &point);

                virtual void fill(video::Renderer *renderer);
                virtual void stroke(video::Renderer *renderer);
                virtual void vectors(video::Renderer *renderer, bool fill);
        };
    }
}

#endif
