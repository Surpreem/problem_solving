#include "problem07.h"

#include <algorithm>
#include <cstdio>


#ifdef _MSC_VER
#   pragma warning(disable : 4996)
#endif


std::vector<int> convert_to_milliseconds(std::string time_str)
{
    auto year{0};
    auto month{0};
    auto day{0};
    auto hour{0};
    auto min{0};
    auto sec{0};
    auto mil{0};
    auto duration{0.0};
    sscanf(
        time_str.c_str(),
        "%d-%d-%d %d:%d:%d.%d %lfs",
        &year, &month, &day, &hour, &min, &sec, &mil, &duration);

    auto const end_time{hour * 3600000 + min * 60000 + sec * 1000 + mil};
    auto const start_time{end_time - static_cast<int>(duration * 1000) + 1};
    return std::vector<int>{start_time, end_time};
}

bool is_in_throughput_window(
    std::vector<int> const& throughput_time,
    std::vector<int> const& process_time)
{
    if (throughput_time.at(0) <= process_time.at(1)
        && throughput_time.at(1) >= process_time.at(0))
        return true;
    else
        return false;
}

std::vector<int> throughput_window_time(int const time)
{
    return std::vector<int>{time, time + 1000 - 1};
}

int max_throughput(std::vector<std::string> const& times)
{
    std::vector<std::vector<int>> process_times;
    for (auto const& time : times)
        process_times.emplace_back(convert_to_milliseconds(time));

    auto max_throughput{0};
    auto throuthput{0};
    for (auto const& time1 : process_times)
        for (auto const& t : time1) {   // {start time, end time}
            auto const throughput_window{throughput_window_time(t)};
            for (auto const& time2 : process_times)
                if (is_in_throughput_window(throughput_window, time2))
                    ++throuthput;

            max_throughput = std::max(max_throughput, throuthput);
            throuthput = 0;
        }

    return max_throughput;
}
