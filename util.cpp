#include "util.h"

std::vector<std::string> split(std::string string, std::string value)
{
    std::string buf; // Have a buffer string
    std::stringstream ss(string); // Insert the string into a stream

    std::vector<std::string> tokens; // Create vector to hold our words

    while (ss >> buf)
        tokens.push_back(buf);
    return tokens;
}

std::vector<std::string> a_split(std::string const &string, std::string const &delimit)
{
    std::string s = "scott>=tiger>=mushroom";
    std::string delimiter = ">=";

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
#ifdef DEBUG
        std::cout << token << std::endl;
#endif
        s.erase(0, pos + delimiter.length());
    }
#ifdef DEBUG
    std::cout << s << std::endl;
#endif
}
