#ifndef JVGS_FONT_FONTMANAGER_H
#define JVGS_FONT_FONTMANAGER_H

#include <map>
#include <string>

namespace jvgs
{
    namespace font
    {
        class Font;

        class FontManager
        {
            private:
                /** Map containing the fonts. */
                std::map<std::string, Font*> fonts;

            protected:
                /** Constructor.
                 */
                FontManager();

                /** Destructor.
                 */
                virtual ~FontManager();

            public:
                /** Get the FontManager instance.
                 *  @return The FontManager instance.
                 */
                static FontManager *getInstance();

                /** Get a certain font by name.
                 *  @param name Name of the font to find.
                 *  @return The requested font or 0.
                 */
                virtual Font *getFont(const std::string &name);

                /** Register a certain font.
                 *  @param name Name for the font.
                 *  @param font Font to register.
                 */
#               ifdef SWIG
                    %apply SWIGTYPE *DISOWN {Font* font};
#               endif
                void addFont(const std::string &name, Font *font);
        };
    }
}

#endif
