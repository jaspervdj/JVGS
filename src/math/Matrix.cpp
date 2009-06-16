#include "Matrix.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

namespace jvgs
{
    namespace math
    {
        Matrix::Matrix(int height, int width)
        {
            this->height = height;
            this->width = width;
            values = new float[height * width];
            for(int row = 0; row < height; row++) {
                for(int column = 0; column < width; column++) {
                    values[width * row + column] =
                            (column == row ? 1.0f : 0.0f);
                }
            }
        }

        Matrix::Matrix(const Matrix &other)
        {
            this->height = other.height;
            this->width = other.width;
            values = new float[height * width];
            for(int row = 0; row < height; row++) {
                for(int column = 0; column < width; column++) {
                    values[width * row + column] =
                            other.values[width * row + column];
                }
            }
        }

        Matrix::~Matrix()
        {
            delete[] values;
        }

        int Matrix::getHeight() const
        {
            return height;
        }

        int Matrix::getWidth() const
        {
            return width;
        }

        void Matrix::setValue(int row, int column, float value)
        {
            values[row * width + column] = value;
        }

        const float &Matrix::getValue(int row, int column) const
        {
            return values[row * width + column];
        }

        const Matrix &Matrix::operator=(const Matrix &other)
        {
            if(height != other.height || width != other.width)
                LogManager::getInstance()->error(
                        "Cannot assign a %dx%d matrix to a %dx%d matrix.",
                        other.height, other.width, height, width);
            for(int row = 0; row < height; row++)
                for(int column = 0; column < width; column++)
                    values[row * width + column] =
                            other.values[row * width + column];

            return *this;
        }

        const Matrix &Matrix::operator+=(const Matrix &other)
        {
            if(height != other.height || width != other.width)
                LogManager::getInstance()->error(
                        "Cannot add a %dx%d matrix to a %dx%d matrix.",
                        other.height, other.width, height, width);
            for(int row = 0; row < height; row++)
                for(int column = 0; column < width; column++)
                    values[row * width + column] +=
                            other.values[row * width + column];

            return *this;
        }

        const Matrix &Matrix::operator-=(const Matrix &other)
        {
            if(height != other.height || width != other.width)
                LogManager::getInstance()->error(
                        "Cannot subtract a %dx%d matrix from a %dx%d matrix.",
                        other.height, other.width, height, width);
            for(int row = 0; row < height; row++)
                for(int column = 0; column < width; column++)
                    values[row * width + column] -=
                            other.values[row * width + column];

            return *this;
        }

        const Matrix &Matrix::operator*=(const float &scalar)
        {
            for(int row = 0; row < height; row++)
                for(int column = 0; column < width; column++)
                    values[row * width + column] *= scalar;

            return *this;
        }

        const Matrix &Matrix::operator/=(const float &scalar)
        {
            float factor = 1 / scalar;

            for(int row = 0; row < height; row++)
                for(int column = 0; column < width; column++)
                    values[row * width + column] *= factor;

            return *this;
        }

        Matrix Matrix::operator+(const Matrix &other) const
        {
            Matrix result(*this);
            result += other;
            return result;
        }

        Matrix Matrix::operator-(const Matrix &other) const
        {
            Matrix result(*this);
            result -= other;
            return result;
        }

        Matrix Matrix::operator*(const float &scalar) const
        {
            Matrix result(*this);
            result *= scalar;
            return result;
        }

        Matrix Matrix::operator/(const float &scalar) const
        {
            Matrix result(*this);
            result /= scalar;
            return result;
        }

        const Matrix &Matrix::operator*=(const Matrix &other)
        {
            Matrix result = *this * other;
            *this = result;
            return *this;
        }

        Matrix Matrix::operator*(const Matrix &other) const
        {
            if(width != other.height)
                LogManager::getInstance()->error(
                        "Cannot multiply a %dx%d matrix with a %dx%d matrix.",
                        other.height, other.width, height, width);

            Matrix result(height, other.width);
            for(int row = 0; row < result.getHeight(); row++) {
                for(int column = 0; column < result.getWidth(); column++) {
                    float sum = 0.0f;
                    for(int i = 0; i < width; i++)
                        sum += getValue(row, i) * other.getValue(i, column);
                    result.setValue(row, column, sum);
                }
            }

            return result;
        }
    }
}
