#include "problem04.h"

#include <cstdio>
#include <map>

#ifdef _MSC_VER
#   pragma warning(disable : 4996)
#endif


void make_queuing_time_table(
    std::vector<std::string> const& time_table,
    std::map<int, int>& time_count,
    int const& last_shuttle_time)
{
    auto hours{0};
    auto minutes{0};
    auto time_minutes{0};
    for (auto const& time : time_table) {
        std::sscanf(time.c_str(), "%d:%d", &hours, &minutes);
        time_minutes = hours * 60 + minutes;
        if (last_shuttle_time < time_minutes)
            continue;

        auto const iter{time_count.find(time_minutes)};
        if (time_count.end() != iter)
            ++(iter->second);
        else
            time_count.emplace(std::make_pair(time_minutes, 1));
    }
}

std::string make_string_time(int const arrival_time) {
    char time[6]{0};
    sprintf(time, "%02d:%02d", arrival_time / 60, arrival_time % 60);
    return time;
}

std::string calculate_arrival_time(
    int const& n,
    int const& t,
    int const& m,
    std::vector<std::string> const& time_table)
{
    std::map<int, int> time_count;
    auto const last_shuttle_count{n - 1};
    auto const last_shuttle_time{9 * 60 + last_shuttle_count * t};
    make_queuing_time_table(time_table, time_count, last_shuttle_time);
    
    auto capacity{m};
    auto arrival_time{last_shuttle_time};
    // just before the last shuttle
    for (auto count{0}; last_shuttle_count > count; ++count) {
        auto const shuttle_time{9 * 60 + count * t};
        for (auto iter{time_count.begin()}; time_count.end() != iter;) {
            if (shuttle_time >= iter->first) {
                capacity -= iter->second;
                if (0 <= capacity) {
                    iter = time_count.erase(iter);
                } else {
                    iter->second = -capacity;
                    capacity = m;
                    break;
                }
            } else {
                capacity = m;
                break;
            }
        }
    }

    // the last shuttle
    for (auto iter{time_count.begin()}; time_count.end() != iter;) {
        if (last_shuttle_time >= iter->first) {
            capacity -= iter->second;
            if (0 < capacity) {
                iter = time_count.erase(iter);
            } else {
                arrival_time = iter->first - 1;
                break;
            }
        }
    }

    return make_string_time(arrival_time);
}
