#ifndef HA_UTIL_H
#define HA_UTIL_H

#include <string>
#include <vector>
#include <sstream>

#define DEBUG

#ifdef DEBUG
    #include <iostream>
#endif

std::vector<std::string> split(std::string string, std::string delimiter);
std::vector<std::string> a_split(std::string const &string, std::string const &delimiter);
#endif // HA_UTIL_H
