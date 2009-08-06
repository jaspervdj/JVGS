#include "Level.h"
#include "Entity.h"

#include "../core/DataManager.h"
using namespace jvgs::core;

#include "../tinyxml/tinyxml.h"

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

        Level::Level(TiXmlElement *element)
        {
            /* Load the world. */
            if(element->Attribute("world")) {
                string worldFileName = element->Attribute("world");
                world = new Sketch(worldFileName);
            } else {
                world = 0;
            }

            /* Walk through the file, adding entities. */
            TiXmlElement *entityElement = element->FirstChildElement("entity");
            while(entityElement) {
                Entity *entity = new Entity(entityElement);
                addEntity(entity);
                entityElement = entityElement->NextSiblingElement("entity");
            }
        }

        Level::~Level()
        {
            if(world)
                delete world;
            for(vector<Entity*>::iterator iterator = entities.begin();
                    iterator != entities.end(); iterator++)
                delete (*iterator);
        }

        void Level::addEntity(Entity *entity)
        {
            entities.push_back(entity);
            entitiesById[entity->getId()] = entity;
        }

        Entity *Level::getEntityById(const string &id)
        {
            map<string, Entity*>::iterator result = entitiesById.find(id);
            if(result != entitiesById.end())
                return result->second;
            else
                return 0;
        }

        void Level::update(float ms)
        {
            for(vector<Entity*>::iterator iterator = entities.begin();
                    iterator != entities.end(); iterator++)
                (*iterator)->update(ms);
        }

        void Level::render()
        {
            world->getSize();
            if(world)
                world->render();

            for(vector<Entity*>::iterator iterator = entities.begin();
                    iterator != entities.end(); iterator++)
                (*iterator)->render();
        }
    }
}
