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
            world = 0;
        }

        Level::Level(const string &fileName)
        {
            DataManager *dataManager = DataManager::getInstance();
            TiXmlDocument *document =
                    new TiXmlDocument(dataManager->expand(fileName));
            document->LoadFile();
            Level::Level(document->RootElement());
            delete document;
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
