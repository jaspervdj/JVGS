%module jvgslua
%include <std_string.i>

%{
#include "../audio/AudioManager.h"
#include "../bind/ScriptManager.h"
#include "../math/Matrix.h"
#include "../math/AffineTransformationMatrix.h"
#include "../math/BoundedObject.h"
#include "../math/BoundingBox.h"
#include "../math/CollisionDetector.h"
#include "../math/PathSegment.h"
#include "../math/Curve.h"
#include "../math/CubicCurve.h"
#include "../math/Line.h"
#include "../math/LineSegment.h"
#include "../math/MathManager.h"
#include "../math/Noise.h"
#include "../math/QuadTree.h"
#include "../math/QuadTreeNode.h"
#include "../math/QuadraticCurve.h"
#include "../math/Vector2D.h"
#include "../core/DataManager.h"
#include "../core/LogManager.h"
#include "../core/XMLLoadable.h"
#include "../core/PropertyMap.h"
#include "../core/PersistenceManager.h"
#include "../core/TimeManager.h"
#include "../core/View.h"
#include "../effect/EffectManager.h"
#include "../effect/InvertEffect.h"
#include "../effect/TextEffect.h"
#include "../font/Font.h"
#include "../font/FontManager.h"
#include "../input/InputManager.h"
#include "../input/Key.h"
#include "../input/KeyListener.h"
#include "../game/AbstractEntity.h"
#include "../game/Affector.h"
#include "../game/AffectorFactory.h"
#include "../game/Animation.h"
#include "../game/Controller.h"
#include "../game/BullController.h"
#include "../game/Camera.h"
#include "../game/CameraFactory.h"
#include "../game/Positioner.h"
#include "../game/CollisionDestroyPositioner.h"
#include "../game/CollisionResponsePositioner.h"
#include "../game/ControllerFactory.h"
#include "../game/Entity.h"
#include "../game/EntityEvent.h"
#include "../game/FlyStraightController.h"
#include "../game/FollowCamera.h"
#include "../game/InputController.h"
#include "../game/Level.h"
#include "../game/LevelManager.h"
#include "../game/NaivePositioner.h"
#include "../game/PositionerFactory.h"
#include "../game/SillyController.h"
#include "../game/Sprite.h"
#include "../sketch/SketchElement.h"
#include "../sketch/Group.h"
#include "../sketch/Path.h"
#include "../sketch/PathComponent.h"
#include "../sketch/Sketch.h"
#include "../sketch/SketchElementRenderer.h"
#include "../sketch/SketchManager.h"
#include "../video/Color.h"
#include "../video/ListManager.h"
#include "../video/Renderer.h"
#include "../video/VideoManager.h"
using namespace jvgs::audio;
using namespace jvgs::bind;
using namespace jvgs::math;
using namespace jvgs::game;
using namespace jvgs::input;
using namespace jvgs::video;
using namespace jvgs::sketch;
using namespace jvgs;
%}

%include "../audio/AudioManager.h"
%include "../bind/ScriptManager.h"
%include "../math/Matrix.h"
%include "../math/AffineTransformationMatrix.h"
%include "../math/BoundedObject.h"
%include "../math/BoundingBox.h"
%include "../math/CollisionDetector.h"
%include "../math/PathSegment.h"
%include "../math/Curve.h"
%include "../math/CubicCurve.h"
%include "../math/Line.h"
%include "../math/LineSegment.h"
%include "../math/MathManager.h"
%include "../math/Noise.h"
%include "../math/QuadTree.h"
%include "../math/QuadTreeNode.h"
%include "../math/QuadraticCurve.h"
%include "../math/Vector2D.h"
%include "../core/DataManager.h"
%include "../core/LogManager.h"
%include "../core/XMLLoadable.h"
%include "../core/PropertyMap.h"
%include "../core/PersistenceManager.h"
%include "../core/TimeManager.h"
%include "../core/View.h"
%include "../effect/EffectManager.h"
%include "../effect/InvertEffect.h"
%include "../effect/TextEffect.h"
%include "../font/Font.h"
%include "../font/FontManager.h"
%include "../input/InputManager.h"
%include "../input/Key.h"
%include "../input/KeyListener.h"
%include "../game/AbstractEntity.h"
%include "../game/Affector.h"
%include "../game/AffectorFactory.h"
%include "../game/Animation.h"
%include "../game/Controller.h"
%include "../game/BullController.h"
%include "../game/Camera.h"
%include "../game/CameraFactory.h"
%include "../game/Positioner.h"
%include "../game/CollisionDestroyPositioner.h"
%include "../game/CollisionResponsePositioner.h"
%include "../game/ControllerFactory.h"
%include "../game/Entity.h"
%include "../game/EntityEvent.h"
%include "../game/FlyStraightController.h"
%include "../game/FollowCamera.h"
%include "../game/InputController.h"
%include "../game/Level.h"
%include "../game/LevelManager.h"
%include "../game/NaivePositioner.h"
%include "../game/PositionerFactory.h"
%include "../game/SillyController.h"
%include "../game/Sprite.h"
%include "../sketch/SketchElement.h"
%include "../sketch/Group.h"
%include "../sketch/Path.h"
%include "../sketch/PathComponent.h"
%include "../sketch/Sketch.h"
%include "../sketch/SketchElementRenderer.h"
%include "../sketch/SketchManager.h"
%include "../video/Color.h"
%include "../video/ListManager.h"
%include "../video/Renderer.h"
%include "../video/VideoManager.h"
