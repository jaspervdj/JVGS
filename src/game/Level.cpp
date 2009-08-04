#include "Level.h"
#include "Entity.h"

using namespace jvgs::sketch;
using namespace std;

namespace jvgs
{
    namespace game
    {
        Level::Level()
        {
            world = 0;
        }

        Level::~Level()
        {
            if(world)
                delete world;
            for(vector<Entity*>::iterator iterator = entities.begin();
                    iterator != entities.end(); iterator++)
                delete (*iterator);
        }

        void Level::update(float ms)
        {
            for(vector<Entity*>::iterator iterator = entities.begin();
                    iterator != entities.end(); iterator++)
                (*iterator)->update(ms);
        }

        void Level::render()
        {
            if(world)
                world->render();

            for(vector<Entity*>::iterator iterator = entities.begin();
                    iterator != entities.end(); iterator++)
                (*iterator)->render();
        }
    }
}
