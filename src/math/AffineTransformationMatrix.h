#ifndef JVGS_MATH_AFFINETRANSFORMATIONMATRIX_H
#define JVGS_MATH_AFFINETRANSFORMATIONMATRIX_H

#include "Matrix.h"
#include "Vector2D.h"

namespace jvgs
{
    namespace math
    {
        /** Special Matrix that represents a 2D affine
         *  transformation.
         */
        class AffineTransformationMatrix: public Matrix
        {
            private:
            public:
                /** Default constructor. This creates the identity matrix.
                 */
                AffineTransformationMatrix();

                /** Specific constructor. Creates a matrix like
                 *  <code>
                 *      / r0c0 r0c1 r0c2 \
                 *      | r1c0 r1c1 r1c2 |
                 *      \    0    0    1 /
                 *  </code>
                 *  @param r0c0 [0,0] element
                 *  @param r0c1 [0,1] element
                 *  @param r0c0 [0,2] element
                 *  @param r1c0 [1,0] element
                 *  @param r1c1 [1,1] element
                 *  @param r1c2 [1,2] element
                 */
                AffineTransformationMatrix(float r0c0, float r0c1, float r0c2,
                                           float r1c0, float r1c1, float r1c2);

                /** Destructor.
                 */
                virtual ~AffineTransformationMatrix();

                /** Applies this matrix to a vector.
                 *  @param other Vector to alply this tranformation to.
                 *  @return The transformed vector.
                 */
                virtual Vector2D operator*(const Vector2D &other) const;

                /** Multiplies this object with a translation matrix.
                 *  @param vector Vector2D to translate over.
                 */
                virtual void translate(const Vector2D &vector);

                /** Multiplies this object with a scale matrix.
                 *  @param vector Vector containing the scale values.
                 */
                virtual void scale(const Vector2D &vector);

                /** Multiplies this object with a rotation matrix.
                 *  @param degrees Degrees to rotate, clockwise.
                 */
                virtual void rotate(float degrees);

                /** Rotates around a given point.
                 *  @param degrees Degrees to rotate, clockwise.
                 *  @param point Point to rotate around.
                 */
                virtual void rotate(float degrees, const Vector2D &point);

                /** Multiplies with an X axis skew matrix.
                 *  @param degrees Degrees to skew.
                 */
                virtual void skewX(float degrees);

                /** Multiplies with an Y axis skew matrix.
                 *  @param degrees Degrees to skew.
                 */
                virtual void skewY(float degrees);
        };
    }
}

#endif
