#include "FontManager.h"
#include "Font.h"

using namespace std;

namespace jvgs
{
    namespace font
    {
        FontManager::FontManager()
        {
        }

        FontManager::~FontManager()
        {
            for(map<string, Font*>::iterator iterator = fonts.begin();
                    iterator != fonts.end(); iterator++)
                delete iterator->second;
        }

        FontManager *FontManager::getInstance()
        {
            static FontManager instance;
            return &instance;
        }

        Font *FontManager::getFont(const string &name)
        {
            map<string, Font*>::iterator result = fonts.find(name);
            if(result != fonts.end())
                return result->second;
            else
                return 0;
        }

        void FontManager::addFont(const string &name, Font *font)
        {
            fonts["name"] = font;
        }
    }
}
