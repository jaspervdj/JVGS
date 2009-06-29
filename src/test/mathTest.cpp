#include "../math/CubicCurve.h"
#include "../math/Vector2D.h"
using namespace jvgs::math;

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    CubicCurve curve(Vector2D(0.0f, 0.0f), Vector2D(0.0f, 50.0f),
                     Vector2D(100.0f, 50.0f), Vector2D(100.0f, 0.0f));
    cout << curve.getLength() << endl;
    return 0;
}
