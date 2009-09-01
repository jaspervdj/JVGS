#ifndef JVGS_CORE_XMLLOADABLE_H
#define JVGS_CORE_XMLLOADABLE_H

#include <string>
class TiXmlElement;

namespace jvgs
{
    namespace core
    {
        /** Generic interface for objects loadable through XML.
         */
        class XMLLoadable
        {
            public:
                /** Constructor.
                 */
                XMLLoadable();

                /** Destructor.
                 */
                virtual ~XMLLoadable();

                /** Check for a boolean attribute.
                 *  @param element Element containing the attribute.
                 *  @param attribute Name of the attribute.
                 *  @param value Will contain value of the attribute.
                 */
                virtual void queryBoolAttribute(TiXmlElement *element,
                        const std::string &attribute, bool *value) const;

                /** Load data from an XML element. Call this function.
                 *  @param element XML element to load data from.
                 */
                virtual void load(TiXmlElement *element);

                /** Load data from an XML file.
                 *  @param fileName XML file to load data from.
                 */
                virtual void load(const std::string &fileName);

            protected:

                /** Load the data. Implement this function.
                 *  @param element XML element to load data from.
                 */
                virtual void loadData(TiXmlElement *element) = 0;
        };
    }
}

#endif
