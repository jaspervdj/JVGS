#ifndef JVGS_GAME_CAMERAFACTORY_H
#define JVGS_GAME_CAMERAFACTORY_H

class TiXmlElement;

namespace jvgs
{
    namespace game
    {
        class Camera;
        class Level;

        class CameraFactory
        {
            public:
                CameraFactory();
                virtual ~CameraFactory();

                virtual Camera *create(TiXmlElement *element, Level *level) 
                        const = 0;
        };

        template <class T>
        class TCameraFactory: public CameraFactory
        {
            private:
            public:
                TCameraFactory()
                {
                }

                virtual ~TCameraFactory()
                {
                }

                virtual Camera *create(TiXmlElement *element, Level *level)
                        const
                {
                    return new T(element, level);
                }
        };
    }
}

#endif
