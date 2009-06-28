#ifndef JVGS_MATH_ELLIPSE_H
#define JVGS_MATH_ELLIPSE_H

namespace jvgs
{
    namespace math
    {
        class Ellipse
        {
            private:
                float xRadius, yRadius;
            public:
                Ellipse(float xRadius, float yRadius);
                virtual ~Ellipse();
        };
    }
}

#endif
