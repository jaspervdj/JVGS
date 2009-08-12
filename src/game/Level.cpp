#include "Level.h"
#include "Entity.h"
#include "FollowCamera.h"
#include "CameraFactory.h"

#include "../core/DataManager.h"
#include "../core/LogManager.h"
using namespace jvgs::core;

#include "../video/VideoManager.h"
using namespace jvgs::video;

#include "../tinyxml/tinyxml.h"

using namespace jvgs::sketch;
using namespace std;

namespace jvgs
{
    namespace game
    {
        /* Filling. */
        map<string, CameraFactory*> createCameraFactories()
        {
            map<string, CameraFactory*> cameraFactories;

            static TCameraFactory<FollowCamera> followCameraFactory;
            cameraFactories["FollowCamera"] = &followCameraFactory;

            return cameraFactories;
        }

        /* Implementation. */
        map<string, CameraFactory*> Level::cameraFactories =
                createCameraFactories();

        void Level::loadData(TiXmlElement *element)
        {
            /* Load the world. */
            if(element->Attribute("world")) {
                string worldFileName = element->Attribute("world");
                world = new Sketch(worldFileName);
            } else {
                LogManager::getInstance()->warning(
                        "No world attribute specified in the level xml.");
                world = 0;
            }

            /* Walk through the file, adding entities. */
            TiXmlElement *entityElement = element->FirstChildElement("entity");
            while(entityElement) {
                Entity *entity = new Entity(entityElement, this);
                addEntity(entity);
                entityElement = entityElement->NextSiblingElement("entity");
            }

            /* Add the camera. */
            TiXmlElement *cameraElement = element->FirstChildElement("camera");
            if(cameraElement) {
                string type = cameraElement->Attribute("type");
                map<string, CameraFactory*>::iterator result =
                        cameraFactories.find(type);
                if(result != cameraFactories.end()) {
                    camera = result->second->create(cameraElement, this);
                } else {
                    LogManager::getInstance()->error("No camera %s",
                            type.c_str());
                }
            }
        }

        Level::Level()
        {
            world = 0;
            camera = 0;
        }

        Level::Level(TiXmlElement *element)
        {
            load(element);
        }

        Level::Level(const string &fileName)
        {
            load(fileName);
        }

        Level::~Level()
        {
            if(world)
                delete world;
            for(vector<Entity*>::iterator iterator = entities.begin();
                    iterator != entities.end(); iterator++)
                delete (*iterator);
            if(camera)
                delete camera;
        }

        Sketch *Level::getWorld() const
        {
            return world;
        }

        void Level::addEntity(Entity *entity)
        {
            entities.push_back(entity);
            entitiesById[entity->getId()] = entity;
            entity->on("spawn");
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
            if(camera)
                camera->update(ms);

            for(vector<Entity*>::iterator iterator = entities.begin();
                    iterator != entities.end(); iterator++)
                (*iterator)->update(ms);
        }

        void Level::render()
        {
            VideoManager::getInstance()->push();

            if(camera)
                camera->transform();

            if(world)
                world->render();

            for(vector<Entity*>::iterator iterator = entities.begin();
                    iterator != entities.end(); iterator++)
                (*iterator)->render();

            VideoManager::getInstance()->pop();
        }
    }
}
