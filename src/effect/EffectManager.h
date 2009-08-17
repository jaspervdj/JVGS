#ifndef JVGS_EFFECT_EFFECTMANAGER_H
#define JVGS_EFFECT_EFFECTMANAGER_H

#include "../core/View.h"
#include <vector>

namespace jvgs
{
    namespace effect
    {
        /** Singleton class to manage effects.
         */
        class EffectManager: public core::View
        {
            private:
                /** List of effects. */
                std::vector<View*> effects;

            protected:
                /** Constructor.
                 */
                EffectManager();

                /** Destructor.
                 */
                virtual ~EffectManager();

            public:
                /** Get the EffectManager instance.
                 *  @return The EffectManager instance.
                 */
                static EffectManager *getInstance();

                /** Add an effect. You don't need to worry about this effect
                 *  now anymore.
                 *  @param effect Effect to add.
                 */
#               ifdef SWIG
                    %apply SWIGTYPE *DISOWN {core::View* effect};
#               endif
                void addEffect(core::View *effect);

                /** Remove all effects.
                 */
                void clear();

                /* Override
                 */
                virtual void update(float ms);

                /* Override
                 */
                virtual void render();
        };
    }
}

#endif
