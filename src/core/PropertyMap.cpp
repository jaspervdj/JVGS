#include "PropertyMap.h"
#include "LogManager.h"

#include "../tinyxml/tinyxml.h"
using namespace std;

namespace jvgs
{
    namespace core
    {
        void PropertyMap::loadData(TiXmlElement *element)
        {
            TiXmlElement *entry = element->FirstChildElement("entry");
            while(entry) {

                if(!entry->Attribute("key"))
                    LogManager::getInstance()->error(
                            "A key should always be defined in a map!");

                string key = entry->Attribute("key");

                string value = entry->Attribute("value") ?
                        entry->Attribute("value") : "1";

                entries[key] = value;
                entry = entry->NextSiblingElement("entry");
            }
        }

        PropertyMap::PropertyMap()
        {
        }

        PropertyMap::PropertyMap(TiXmlElement *element)
        {
            load(element);
        }

        PropertyMap::PropertyMap(const string &fileName)
        {
            load(fileName);
        }

        PropertyMap::~PropertyMap()
        {
        }

        bool PropertyMap::isSet(const string &key)
        {
            map<string, string>::iterator result = entries.find(key);
            return result != entries.end();
        }

        string PropertyMap::get(const string &key)
        {
            map<string, string>::iterator result = entries.find(key);
            return result != entries.end() ? result->second : "";
        }

        bool PropertyMap::get(const string &key, string *value)
        {
            map<string, string>::iterator result = entries.find(key);
            if(result != entries.end()) {
                (*value) = result->second;
                return true;
            } else {
                return false;
            }
        }

        bool PropertyMap::getBool(const string &key)
        {
            map<string, string>::iterator result = entries.find(key);
            return result != entries.end() ? result->second == "true" : false;
        }

        void PropertyMap::set(const string &key, const string &value)
        {
            entries[key] = value;
        }

        void PropertyMap::setBool(const string &key, bool value)
        {
            entries[key] = value ? "true" : "false";
        }

        void PropertyMap::write(const string &fileName)
        {
            TiXmlDocument document(fileName);
            TiXmlElement root("propertymap");

            for(map<string, string>::iterator iterator = entries.begin();
                    iterator != entries.end(); iterator++) {
                TiXmlElement element("entry");
                element.SetAttribute("key", iterator->first);
                element.SetAttribute("value", iterator->second);
                root.InsertEndChild(element);
            }

            document.InsertEndChild(root);
            if(!document.SaveFile())
                LogManager::getInstance()->error(
                        "Could not save to %s", fileName.c_str());
        }
    }
}
