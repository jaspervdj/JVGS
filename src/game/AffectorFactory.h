#ifndef JVGS_GAME_AFFECTORFACTORY_H
#define JVGS_GAME_AFFECTORFACTORY_H

class TiXmlElement;

namespace jvgs
{
    namespace game
    {
        class Entity;

        template <class T>
        class AffectorFactory
        {
            public:
                AffectorFactory()
                {
                }

                virtual ~AffectorFactory()
                {
                }

                virtual T *create(Entity *entity, TiXmlElement *element)
                        const = 0;
        };
    }
}

#endif
