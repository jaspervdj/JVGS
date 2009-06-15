#include <iostream>
using namespace std;

#include "../math/Matrix.h"
using namespace jvgs::math;

void print(const Matrix &matrix)
{
    for(int y=0; y<matrix.getHeight(); y++) {
        for(int x=0; x<matrix.getWidth(); x++) {
            cout << matrix.getValue(y, x) << "  ";
        }
        cout << endl;
    }
}

int main(int argc, char **argv)
{
    Matrix mat1(3,2);
    Matrix mat2(2,1);

    mat1.setValue(0,0,2);
    mat1.setValue(0,1,4);
    mat1.setValue(1,0,7);
    mat1.setValue(1,1,2);
    mat1.setValue(2,0,0);
    mat1.setValue(2,1,1);

    mat2.setValue(0,0,3);
    mat2.setValue(1,0,9);

    print(mat1 * mat2);

    return 0;
}
