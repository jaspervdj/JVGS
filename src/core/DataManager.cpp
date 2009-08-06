#include "DataManager.h"

using namespace std;

namespace jvgs
{
    namespace core
    {
        DataManager::DataManager()
        {
            dataDirectory = "./";
        }

        DataManager::~DataManager()
        {
        }

        DataManager *DataManager::getInstance()
        {
            static DataManager instance;
            return &instance;
        }

        const string &DataManager::getDataDirectory() const
        {
            return dataDirectory;
        }

        void DataManager::setDataDirectory(const string &dataDirectory)
        {
            this->dataDirectory = dataDirectory;
        }

        string DataManager::expand(const string &fileName) const
        {
            /* dataDirectory ends in '/', so fileName should not begin with a 
             * '/'. */
            if(fileName[0] == '/')
                return dataDirectory + fileName.substr(1);
            else
                return dataDirectory + fileName;
        }
    }
}
