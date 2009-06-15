#include "LogManager.h"

#include <cstdlib>
#include <cstdarg>

namespace jvgs
{
    namespace core
    {
        LogManager::LogManager()
        {
        }

        LogManager::~LogManager()
        {
        }

        LogManager *LogManager::getInstance()
        {
            static LogManager instance;
            return &instance;
        }

        void LogManager::message( const char *fmt, ... )
        {
            va_list arg;

            va_start( arg, fmt );

            fprintf( stdout, "Message - " );
            vfprintf( stdout, fmt, arg );
            fprintf( stdout, "\n" );

            va_end( arg );
        }

        void LogManager::warning( const char *fmt, ... )
        {
            va_list arg;

            va_start( arg, fmt );

            fprintf( stderr, "Warning - " );
            vfprintf( stderr, fmt, arg );
            fprintf( stderr, "\n" );

            va_end( arg );
        }

        void LogManager::error( const char *fmt, ... )
        {
            va_list arg;

            va_start( arg, fmt );

            fprintf( stderr, "Error - " );
            vfprintf( stderr, fmt, arg );
            fprintf( stderr, "\n" );

            va_end( arg );

            exit(1);
        }
    };
};
