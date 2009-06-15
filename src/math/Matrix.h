#ifndef JVGS_MATH_MATRIX_H
#define JVGS_MATH_MATRIX_H

namespace jvgs
{
    namespace math
    {
        class Matrix
        {
            private:
                int height, width;
                float *values;

            public:
                Matrix(int height, int width);
                Matrix(const Matrix &other);
                virtual ~Matrix();

                int getHeight() const;
                int getWidth() const;

                void setValue(int row, int column, float value);
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
