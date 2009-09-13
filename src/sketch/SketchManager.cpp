#include "SketchManager.h"
#include "Sketch.h"

using namespace std;

namespace jvgs
{
    namespace sketch
    {
        SketchManager::SketchManager()
        {
        }

        SketchManager::~SketchManager()
        {
            clear();
        }

        SketchManager* SketchManager::getInstance()
        {
            static SketchManager instance;
            return &instance;
        }

        void SketchManager::clear()
        {
            /* Delete all loaded sketches. */
            for(map<string, Sketch*>::iterator iterator = sketches.begin();
                    iterator != sketches.end(); iterator++)
                delete iterator->second;
            sketches.clear();
        }

        Sketch *SketchManager::getSketch(const string &fileName)
        {
            Sketch *sketch;

            /* Look for the file name in the already loaded sketches. */
            map<string, Sketch*>::iterator result = sketches.find(fileName);

            /* Found, restore from memory. */
            if(result != sketches.end()) {
                sketch = result->second;

            /* Not found, load. */
            } else {
                sketch = new Sketch(fileName);
                sketches[fileName] = sketch;
            }

            return sketch;
        }
    }
}
