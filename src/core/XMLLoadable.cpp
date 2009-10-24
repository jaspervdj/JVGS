#include "XMLLoadable.h"
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

        void XMLLoadable::queryBoolAttribute(TiXmlElement *element,
                const string &attribute, bool *value) const
        {
            if(element->Attribute(attribute)) {
                string str = element->Attribute(attribute.c_str());
                if(str == "true")
                    *value = true;
                else if(str == "false")
                    *value = false;
                else
                    LogManager::getInstance()->error(
                            "Bool attributes should be true or false.");
            }
        }

        void XMLLoadable::load(TiXmlElement *element)
        {
            /* First load data from another file. */
            if(element->Attribute("filename"))
                load(element->Attribute("filename"));
            /* Now load the specific data. */
            loadData(element);
        }

        void XMLLoadable::load(const string &fileName)
        {
            LogManager *logManager = LogManager::getInstance();

            TiXmlDocument *document = new TiXmlDocument(fileName);
            if(document->LoadFile()) {
                load(document->RootElement());
            } else {
                logManager->warning("Could not load xml document: %s.",
                        fileName.c_str());
            }
            delete document;
        }
    }
}
