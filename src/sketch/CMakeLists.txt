ADD_LIBRARY( 
    sketch SHARED 
    Group.cpp
    GroupParser.cpp
    GroupRenderer.cpp
    MatrixTransformCommand.cpp
    Path.cpp
    Parser.cpp
    Primitive.cpp
    PrimitiveParser.cpp
    PrimitiveRenderer.cpp
    Rectangle.cpp
    RectangleParser.cpp
    RectangleRenderer.cpp
    Sketch.cpp
    StyleParser.cpp
    TransformParser.cpp
    TransformCommand.cpp
    TextParser.cpp
)

TARGET_LINK_LIBRARIES(
    sketch
    tinyxml
    core
    video
)
