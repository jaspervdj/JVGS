#!/bin/bash

if [[ $# != 2 ]]; then
    echo "Usage: $0 subnamespace classname"
    exit 1
fi

DEFINE_IDENTIFIER=$(echo "jvgs_$1_$2_h" | tr 'a-z' 'A-Z')

if [[ -f src/$1/$2.h ]]; then
    echo "File already exists."
    exit 1
fi

echo "Adding src/$1/$2.h"
cat > src/$1/$2.h << HERE
#ifndef $DEFINE_IDENTIFIER
#define $DEFINE_IDENTIFIER

namespace jvgs
{
    namespace $1
    {
        class $2
        {
            private:
            public:
                $2();
                virtual ~$2();
        };
    }
}

#endif
HERE

echo "Adding src/$1/$2.cpp"
cat > src/$1/$2.cpp << HERE
#include "$2.h"

namespace jvgs
{
    namespace $1
    {
        $2::$2()
        {
        }

        $2::~$2()
        {
        }
    }
}
HERE
