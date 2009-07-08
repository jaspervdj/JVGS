#include "../math/CubicCurve.h"
#include "../math/Vector2D.h"
#include "../math/Line.h"
#include "../math/LineSegment.h"
#include "../math/MathManager.h"
using namespace jvgs::math;

#include <iostream>
using namespace std;


int main(int argc, char **argv)
{
    MathManager *mathManager = MathManager::getInstance();
    mathManager->newRandomSeed();

    Line line(Vector2D(3.0f, 2.0f), Vector2D(1.0f, 5.0f));

    Vector2D v(4.0f, 4.0f);

    for(int i = 0; i < 3; i++) {
        Vector2D closest = line.getClosestPoint(v);

        cout << "Closest point: (" << closest.getX() << ", " << closest.getY()
                << ")" << endl;
        cout << "Distance: " << line.getDistance(v) << endl;
        cout << "Signed distance: " << line.getSignedDistance(v) << endl;

        v.setX(mathManager->randFloat(-10.0f, 10.0f));
        v.setY(mathManager->randFloat(-10.0f, 10.0f));
    }

    return 0;
}
