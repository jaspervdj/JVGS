#ifndef JVGS_MATH_MATRIX_H
#define JVGS_MATH_MATRIX_H

namespace jvgs
{
    namespace math
    {
        /** A general class to perform matrix math.
         */
        class Matrix
        {
            private:
                /** The matrix dimensions. */
                int height, width;

                /** The matrix values, row per row. */
                float *values;

            public:
                /** Constructor. Creates an matrix M with
                 *  m[i,j] = 1 when i = j, and 0 otherwise.
                 *  @param height The matrix height.
                 *  @param width The matrix width.
                 */
                Matrix(int height, int width);

                /** Copy constructor.
                 *  @param other Matrix to be copied.
                 */
                Matrix(const Matrix &other);

                /** Destructor.
                 */
                virtual ~Matrix();

                /** Get the matrix height.
                 *  @return The matrix height.
                 */
                int getHeight() const;

                /** Get the matrix width.
                 *  @return The matrix width.
                 */
                int getWidth() const;

                /** Set a value in the matrix.
                 *  @param row Row index.
                 *  @param column Column index.
                 *  @param value New value.
                 */
                void setValue(int row, int column, float value);

                /** Obtain a value from the matrix.
                 *  @param row Row index.
                 *  @param column Column index.
                 *  @return The matrix value at (row, column).
                 */
                const float &getValue(int row, int column) const;

                const Matrix &operator=(const Matrix &other);
                const Matrix &operator+=(const Matrix &other);
                const Matrix &operator-=(const Matrix &other);
                const Matrix &operator*=(const float &scalar);
                const Matrix &operator/=(const float &scalar);

                Matrix operator+(const Matrix &other) const;
                Matrix operator-(const Matrix &other) const;
                Matrix operator*(const float &scalar) const;
                Matrix operator/(const float &scalar) const;

                const Matrix &operator*=(const Matrix &other);
                Matrix operator*(const Matrix &other) const;
        };
    }
}

#endif
