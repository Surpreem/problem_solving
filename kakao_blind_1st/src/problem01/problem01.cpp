#include "problem01.h"


std::vector<std::string> decypting_map(
    int const size, std::vector<int> const arr1, std::vector<int> const arr2)
{
    std::vector<std::string> map;
    std::string line;
    for (auto i{0}; size != i; ++i) {
        for (auto j{size - 1}; 0 <= j; --j)
            line += (arr1.at(i) | arr2.at(i)) >> j & 0x1 ? "#" : " ";
        map.emplace_back(line);
        line.clear();
    }
    return map;
}
