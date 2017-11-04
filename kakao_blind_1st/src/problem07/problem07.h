#pragma once

#include <string>
#include <utility>
#include <vector>


std::vector<int> convert_to_milliseconds(std::string time_str);
bool is_in_throughput_window(
    std::vector<int> const& throughput_time,
    std::vector<int> const& process_time);
std::vector<int> throughput_window_time(int const time);
int max_throughput(std::vector<std::string> const& times);
