#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "problem07/problem07.h"


SCENARIO("Get process start time and end time in milliseconds", "[problem07]")
{
    GIVEN("Response time and process duration time")
    {
        auto const time_str{"2016-09-15 01:00:04.001 2.0s"};

        WHEN(
            "Convert a string time"
            " to milliseconds elapsed from 2016-09-15 00:00:00.000")
        {
            auto result_time{convert_to_milliseconds(time_str)};

            THEN("Result is the array of start and end time")
            {
                auto expected_time{std::vector<int>{3602002, 3604001}};
                REQUIRE(expected_time.at(0) == result_time.at(0));
                REQUIRE(expected_time.at(1) == result_time.at(1));
            }
        }
    }
}

SCENARIO("Check the process time is in throughput window time", "[problem07]")
{
    GIVEN("Process start time > throughput window end time")
    {
        auto const process_time{std::vector<int>{3602002, 3604001}};
        auto const throughput_window{std::vector<int>{3601002, 3602001}};

        WHEN("Check the process time in throughput window time")
        {
            auto result{
                is_in_throughput_window(throughput_window, process_time)};

            THEN("Result is false")
            {
                REQUIRE(false == result);
            }
        }
    }

    GIVEN("Process start time <= throughput window end time")
    {
        auto const process_time{std::vector<int>{3602002, 3604001}};
        auto const throughput_window{std::vector<int>{3601003, 3602002}};

        WHEN("Check the process time in throughput window time")
        {
            auto result{
                is_in_throughput_window(throughput_window, process_time)};

            THEN("Result is true")
            {
                REQUIRE(true == result);
            }
        }
    }

    GIVEN(
        "Process start time == throughput window start time, "
        "and process end time >= throughput window end time")
    {
        auto const process_time{std::vector<int>{3602002, 3604001}};
        auto const throughput_window{std::vector<int>{3602002, 3603001}};

        WHEN("Check the process time in throughput window time")
        {
            auto result{
                is_in_throughput_window(throughput_window, process_time)};

            THEN("Result is true")
            {
                REQUIRE(true == result);
            }
        }
    }

    GIVEN("Process end time == throughput window start time")
    {
        auto const process_time{std::vector<int>{3602002, 3604001}};
        auto const throughput_window{std::vector<int>{3604001, 3605000}};

        WHEN("Check the process time in throughput window time")
        {
            auto result{
                is_in_throughput_window(throughput_window, process_time)};

            THEN("Result is true")
            {
                REQUIRE(true == result);
            }
        }
    }

    GIVEN("Process end time < throughput window start time")
    {
        auto const process_time{std::vector<int>{3602002, 3604001}};
        auto const throughput_window{std::vector<int>{3604002, 3605001}};

        WHEN("Check the process time in throughput window time")
        {
            auto result{
                is_in_throughput_window(throughput_window, process_time)};

            THEN("Result is false")
            {
                REQUIRE(false == result);
            }
        }
    }

    GIVEN(
        "Process start time >= throughput window start time, "
        "and proces end time <= throughput window end time")
    {
        auto const process_time{std::vector<int>{3602002, 3604001}};
        auto const throughput_window{std::vector<int>{3602002, 3604001}};

        WHEN("Check the process time in throughput window time")
        {
            auto result{
                is_in_throughput_window(throughput_window, process_time)};

            THEN("Result is true")
            {
                REQUIRE(true == result);
            }
        }
    }
}

SCENARIO("Get throughput window time in milliseconds", "[problem07]")
{
    GIVEN("Process time in milliseconds")
    {
        auto const process_time{3602002};

        WHEN("Calculate")
        {
            auto result_time{throughput_window_time(process_time)};

            THEN("Result is the array of throuthput window start and end time")
            {
                auto expected_time{std::vector<int>{3602002, 3603001}};
                REQUIRE(expected_time.at(0) == result_time.at(0));
                REQUIRE(expected_time.at(1) == result_time.at(1));
            }
        }
    }
}

SCENARIO("Get max throughput for 1s", "[problem07]")
{
    GIVEN("The array of response time and process time")
    {
        std::vector<std::string> const times{"2016-09-15 01:00:04.001 2.0s"};

        WHEN("Calculate")
        {
            auto const throughput{max_throughput(times)};

            THEN("Result is 1")
            {
                REQUIRE(1 == throughput);
            }
        }
    }

    GIVEN("The array of response time and process time")
    {
        std::vector<std::string> const times{
            "2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"};

        WHEN("Calculate")
        {
            auto const throughput{max_throughput(times)};

            THEN("Result is 2")
            {
                REQUIRE(2 == throughput);
            }
        }
    }

    GIVEN("The array of response time and process time")
    {
        std::vector<std::string> const times{
            "2016-09-15 20:59:57.421 0.351s",
            "2016-09-15 20:59:58.233 1.181s",
            "2016-09-15 20:59:58.299 0.8s",
            "2016-09-15 20:59:58.688 1.041s",
            "2016-09-15 20:59:59.591 1.412s",
            "2016-09-15 21:00:00.464 1.466s",
            "2016-09-15 21:00:00.741 1.581s",
            "2016-09-15 21:00:00.748 2.31s",
            "2016-09-15 21:00:00.966 0.381s",
            "2016-09-15 21:00:02.066 2.62s"};

        WHEN("Calculate")
        {
            auto const throughput{max_throughput(times)};

            THEN("Result is 7")
            {
                REQUIRE(7 == throughput);
            }
        }
    }
}
