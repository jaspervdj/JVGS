#include "XMLLoadable.h"
#include "DataManager.h"
#include "LogManager.h"

#include "../tinyxml/tinyxml.h"

using namespace std;

namespace jvgs
{
    namespace core
    {
        XMLLoadable::XMLLoadable()
        {
        }

        XMLLoadable::~XMLLoadable()
        {
        }

        bool XMLLoadable::getBoolAttribute(TiXmlElement *element,
                const string &attribute) const
        {
            int value = 0;
            int result = element->QueryIntAttribute(attribute, &value);
            return result == TIXML_SUCCESS && value;
        }

        void XMLLoadable::load(TiXmlElement *element)
        {
            /* First load data from another file. */
            if(element->Attribute("fileName"))
                load(element->Attribute("fileName"));
            /* Now load the specific data. */
            loadData(element);
        }

        void XMLLoadable::load(const string &fileName)
        {
            DataManager *dataManager = DataManager::getInstance();
            LogManager *logManager = LogManager::getInstance();

            TiXmlDocument *document =
                    new TiXmlDocument(dataManager->expand(fileName));
            if(document->LoadFile()) {
                load(document->RootElement());
            } else {
                logManager->error("Could not load xml document: %s.",
                        fileName.c_str());
            }
            delete document;
        }
    }
}
