#include "StyleParser.h"

using namespace jvgs::video;

#include "../core/LogManager.h"
using namespace jvgs::core;

#include <sstream>
#include <iostream>
using namespace std;

namespace jvgs
{
    namespace sketch
    {
        StyleParser::StyleParser(const string &data)
        {
            in = new stringstream(data);

            string line;
            while((*in) >> line) {

                string::size_type colon = line.find_first_of(':');
                while(colon != string::npos) {

                    string::size_type statementEnd = line.find_first_of(';', colon);

                    string statement;
                    if(statementEnd == string::npos) {
                        statement = line;
                        line = "";
                    } else {
                        statement = line.substr(0, statementEnd);
                        line = line.erase(0, statementEnd + 1);
                    }

                    string key = trim(statement.substr(0, colon));
                    string value = trim(statement.substr(colon + 1));

                    values[key] = value;

                    colon = line.find_first_of(':');
                }
            }
        }

        StyleParser::~StyleParser()
        {
            delete in;
        }

        bool StyleParser::hasValue(const string &key)
        {
            return values.find(key) != values.end();
        }

        string StyleParser::getValue(const string &key)
        {
            map<string,string>::iterator iterator = values.find(key);
            if(iterator == values.end())
                return "";
            else
                return iterator->second;
        }

        float StyleParser::getValueAsFloat(const string &key)
        {
            stringstream converter(getValue(key));
            float f;
            converter >> f;
            return f;
        }

        Color StyleParser::getValueAsColor(const string &key)
        {
            string value = getValue(key);
            if(value.length() == 7) {
                if(value[0] == '#') {
                    stringstream redStream(value.substr(1,2));
                    stringstream greenStream(value.substr(3,2));
                    stringstream blueStream(value.substr(5,2));
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
