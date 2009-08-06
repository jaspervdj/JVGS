#ifndef JVGS_CORE_DATAMANAGER_H
#define JVGS_CORE_DATAMANAGER_H

#include <string>

namespace jvgs
{
    namespace core
    {
        /** A class that manages the main data location.
         */
        class DataManager
        {
            private:
                /** The data directory path. */
                std::string dataDirectory;

            protected:
                /** Constructor.
                 */
                DataManager();

                /** Destructor.
                 */
                virtual ~DataManager();

            public:
                /** Get the DataManager instance.
                 *  @return The DataManager instance.
                 */
                static DataManager *getInstance();

                /** Get the data directory.
                 *  @return The data directory.
                 */
                const std::string &getDataDirectory() const;

                /** Set the data directory.
                 *  @param dataDirectory The new data directory.
                 */
                void setDataDirectory(const std::string &dataDirectory);

                /** Expand a file name to a complete file name including the
                 *  data directory.
                 *  @param fileName File name to expand.
                 */
                std::string expand(const std::string &fileName) const;
        };
    }
}

#endif
