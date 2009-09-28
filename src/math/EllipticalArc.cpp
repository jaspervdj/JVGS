#include "EllipticalArc.h"
#include "AffineTransformationMatrix.h"
#include "MathManager.h"
#include <cmath>

namespace jvgs
{
    namespace math
    {
        EllipticalArc::EllipticalArc(const Vector2D &start,
                const Vector2D &radius, float phi, bool largeArc, bool sweep,
                const Vector2D &end)
        {
            this->radius = radius;
            this->phi = phi;
            
            AffineTransformationMatrix rotate, rotateMinus;
            rotate.rotate(phi);
            rotateMinus.rotate(-phi);

            Vector2D tmp1 = rotateMinus * ((start - end) / 2.0f);

            float s = sqrt((
                    radius.getX() * radius.getX() *
                    radius.getY() * radius.getY() -
                    radius.getX() * radius.getX() *
                    tmp1.getY() * tmp1.getY() -
                    radius.getY() * radius.getY() *
                    tmp1.getX() * tmp1.getX()) / (
                    radius.getX() * radius.getX() *
                    tmp1.getY() * tmp1.getY() +
                    radius.getY() * radius.getY() *
                    tmp1.getX() * tmp1.getX()));
            if(largeArc == sweep)
                s = -s;

            Vector2D tmpCenter = Vector2D(
                    radius.getX() * tmp1.getY() / radius.getY(),
                    -radius.getY() * tmp1.getX() / radius.getX() * s);

            center = rotate * tmpCenter + (start + end) / 2.0f;

            theta1 = Vector2D(1.0f, 0.0f).getAngle(Vector2D(
                    (tmp1.getX() - tmpCenter.getX()) / radius.getX(),
                    (tmp1.getY() - tmpCenter.getY()) / radius.getY()));
            deltaTheta = Vector2D(
                    (tmp1.getX() - tmpCenter.getX()) / radius.getX(),
                    (tmp1.getY() - tmpCenter.getY()) / radius.getY()).getAngle(
                    Vector2D((-tmp1.getX() - tmpCenter.getX()) / radius.getX(),
                    (-tmp1.getY() - tmpCenter.getY()) / radius.getY()));

            if(!sweep && deltaTheta > 0.0f)
                deltaTheta -= 360.0f;
            else if(sweep && deltaTheta < 0.0f)
                deltaTheta += 360.0f;

            calculateLength();
        }

        EllipticalArc::~EllipticalArc()
        {
        }

        Vector2D EllipticalArc::getPoint(float t) const
        {
            AffineTransformationMatrix rotate;
            rotate.rotate(phi);
            float theta = theta1 + t * deltaTheta;
            return rotate * Vector2D(radius.getX() * cos(theta * M_PI / 180.0f),
                    radius.getY() * sin(theta * M_PI / 180.0f)) + center;
        }

        float EllipticalArc::getLengthGuess() const
        {
            return MathManager::getInstance()->max<float>(radius.getX(),
                    radius.getY()) * M_PI * 2.0f;
        }
    }
}
