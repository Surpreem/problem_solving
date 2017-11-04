#include "problem03/problem03.h"

#include <algorithm>
#include <cctype>
#include <list>


int cache_performace(size_t const cache_size, std::vector<std::string> cities)
{
    std::list<std::string> lru_cache;
    auto total_time{0};
    
    for (auto city : cities) {
        std::transform(
            city.begin(),
            city.end(),
            city.begin(),
            [](char const& c) {return static_cast<char>(::tolower(c));});
        auto const iter{std::find(lru_cache.cbegin(), lru_cache.cend(), city)};
        if (lru_cache.cend() != iter) {
            total_time += 1;
            lru_cache.erase(iter);
        } else {
            total_time += 5;
        }
        lru_cache.emplace_front(city);

        if (cache_size < lru_cache.size())
            lru_cache.pop_back();
    }

    return total_time;
}
