#include "Group.h"
#include "GroupRenderer.h"

using namespace std;

namespace jvgs
{
    namespace sketch
    {
        Group::Group(Primitive *parent): Primitive(parent)
        {
        }

        Group::~Group()
        {
            vector<Primitive*>::iterator iterator = primitives.begin();
            while (iterator != primitives.end()) {
                delete (*iterator);
                iterator++;
            }
        }

        void Group::addPrimitive(Primitive *primitive)
        {
            primitives.push_back(primitive);
        }

        int Group::getNumberOfPrimitives() const
        {
            return primitives.size();
        }

        Primitive *Group::getPrimitive(int index) const
        {
            return primitives[index];
        }

        PrimitiveRenderer *Group::createPrimitiveRenderer()
        {
            return new GroupRenderer(this);
        }
    }
}
