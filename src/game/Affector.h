#ifndef JVGS_GAME_AFFECTOR_H
#define JVGS_GAME_AFFECTOR_H

namespace jvgs
{
    namespace game
    {
        class Entity;

        /** A class that affects an entity. This could be used for gravity,
         *  controls, collision response, ...
         */
        class Affector
        {
            private:
                Entity *entity;

            public:
                /** Constructor.
                 */
                Affector(Entity *entity);

                /** Destructor.
                 */
                virtual ~Affector();

                /** Get the affected entity.
                 *  @return The affected entity.
                 */
                virtual Entity *getEntity() const;

                /** Get the priority of this affector. The higher the priority,
                 *  the sooner it will be executed.
                 *  @return The priority of this affector.
                 */
                virtual int getPriority() const = 0;

                /** Affect an entity for a certain time.
                 *  @param ms The time to affect the entity for.
                 */
                virtual void affect(float ms) = 0;
        };
    }
}

#endif
