#include "TextParser.h"

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

        void TextParser::split(const string &str, char c,
                vector<string> &destination) const
        {
            string::size_type start = 0;
            string::size_type end = str.find_first_of(c);
            while(end != string::npos) {
                destination.push_back(str.substr(start, end - start));
                start = end + 1;
                end = str.find_first_of(c, start);
            }

            destination.push_back(str.substr(start));
        }
    }
}
