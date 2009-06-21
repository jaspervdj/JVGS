#include "TextParser.h"

#include "../video/Color.h"
using namespace jvgs::video;

#include <sstream>
using namespace std;

namespace jvgs
{
    namespace sketch
    {
        TextParser::TextParser()
        {
        }

        TextParser::~TextParser()
        {
        }

        string TextParser::trim(const string &str) const
        {
            string::size_type pos1 = str.find_first_not_of(' ');
            string::size_type pos2 = str.find_last_not_of(' ');
            return str.substr(pos1 == string::npos ? 0 : pos1,
                    pos2 == string::npos ? str.length() - 1 : pos2 - pos1 + 1);
        }

        void TextParser::split(const string &str, const string &characters,
                vector<string> &destination) const
        {
            string::size_type start = str.find_first_not_of(characters);
            string::size_type end = str.find_first_of(characters, start + 1);
            while(start != string::npos && end != string::npos) {
                destination.push_back(str.substr(start, end - start));
                start = str.find_first_not_of(characters, end + 1);
                end = str.find_first_of(characters, start);
            }

            if(start != string::npos)
                destination.push_back(str.substr(start));
        }

        void TextParser::replaceAll(string &text, const string &from,
                const string &to) const
        {
            size_t lookHere = 0;
            size_t foundHere;
            while((foundHere = text.find(from, lookHere)) != string::npos) {
                text.replace(foundHere, from.size(), to);
                lookHere = foundHere + to.size();
            }
        }

        Color TextParser::parseColor(const string &str) const
        {
            if(str.length() == 7) {
                if(str[0] == '#') {
                    stringstream redStream(str.substr(1,2));
                    stringstream greenStream(str.substr(3,2));
                    stringstream blueStream(str.substr(5,2));
                    int red, green, blue;
                    redStream >> hex >> red;
                    greenStream >> hex >> green;
                    blueStream >> hex >> blue;
                    return Color( (float)red / (float)0xff,
                                  (float)green / (float)0xff,
                                  (float)blue / (float)0xff );
                }
            }

            return Color();
        }
    }
}
