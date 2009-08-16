#include "View.h"

namespace jvgs
{
    namespace core
    {
        View::View()
        {
            garbage = false;
        }

        View::~View()
        {
        }

        bool View::isGarbage() const
        {
            return garbage;
        }

        void View::setGarbage()
        {
            garbage = true;
        }
    }
}
