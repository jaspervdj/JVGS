ADD_LIBRARY( 
    math STATIC 
    AffineTransformationMatrix.cpp
    BoundedObject.cpp
    BoundingBox.cpp
    CubicCurve.cpp
    Curve.cpp
    CollisionDetector.cpp
    EllipticalArc.cpp
    Line.cpp
    LineSegment.cpp
    MathManager.cpp
    Matrix.cpp
    Noise.cpp
    PathSegment.cpp
    QuadraticCurve.cpp
    QuadTree.cpp
    QuadTreeNode.cpp
    Vector2D.cpp
)

TARGET_LINK_LIBRARIES(
    math sketch
)
