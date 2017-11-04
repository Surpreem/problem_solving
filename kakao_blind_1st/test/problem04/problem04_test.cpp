#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "problem04/problem04.h"


SCENARIO("Calculate the last riding time", "[problem04]")
{
    GIVEN("Suttle running time is 1, interval time is 1, capacity is 1")
    {
        auto const n{1};
        auto const t{1};
        auto const m{1};
        std::vector<std::string> const time_table{"08:00"};

        WHEN("Calculate")
        {
            auto result_time{calculate_arrival_time(n, t, m, time_table)};

            THEN("The last time is 07:59")
            {
                auto const expected_time{"07:59"};
                REQUIRE(expected_time == result_time);
            }
        }
    }

    GIVEN("Suttle running time is 1, interval time is 1, capacity is 1")
    {
        auto const n{1};
        auto const t{1};
        auto const m{1};
        std::vector<std::string> const time_table{"09:00"};

        WHEN("Calculate")
        {
            auto result_time{calculate_arrival_time(n, t, m, time_table)};

            THEN("The last time is 08:59")
            {
                auto const expected_time{"08:59"};
                REQUIRE(expected_time == result_time);
            }
        }
    }

    GIVEN("Suttle running time is 1, interval time is 1, capacity is 5")
    {
        auto const n{1};
        auto const t{1};
        auto const m{5};
        std::vector<std::string> const time_table{"08:00", "08:01", "08:02", "08:03"};

        WHEN("Calculate")
        {
            auto result_time{calculate_arrival_time(n, t, m, time_table)};

            THEN("The last time is 09:00")
            {
                auto const expected_time{"09:00"};
                REQUIRE(expected_time == result_time);
            }
        }
    }

    GIVEN("Suttle running time is 2, interval time is 10, capacity is 2")
    {
        auto const n{2};
        auto const t{10};
        auto const m{2};
        std::vector<std::string> const time_table{"09:10", "09:09", "08:00"};

        WHEN("Calculate")
        {
            auto result_time{calculate_arrival_time(n, t, m, time_table)};

            THEN("The last time is 09:09")
            {
                auto const expected_time{"09:09"};
                REQUIRE(expected_time == result_time);
            }
        }
    }

    GIVEN(
        "Suttle running time is 2, interval time is 1, capacity is 2, "
        "four persons wait at 09:00")
    {
        auto const n{2};
        auto const t{10};
        auto const m{2};
        std::vector<std::string> const time_table{
            "09:00", "09:00", "09:00", "09:00"};

        WHEN("Calculate")
        {
            auto result_time{calculate_arrival_time(n, t, m, time_table)};

            THEN("The last time is 08:59")
            {
                auto const expected_time{"08:59"};
                REQUIRE(expected_time == result_time);
            }
        }
    }

    GIVEN(
        "Suttle running time is 1, interval time is 1, capacity is 5, "
        "five persons wait at 00:01")
    {
        auto const n{1};
        auto const t{1};
        auto const m{5};
        std::vector<std::string> const time_table{
            "00:01", "00:01", "00:01", "00:01", "00:01"};

        WHEN("Calculate")
        {
            auto result_time{calculate_arrival_time(n, t, m, time_table)};

            THEN("The last time is 00:00")
            {
                auto const expected_time{"00:00"};
                REQUIRE(expected_time == result_time);
            }
        }
    }

    GIVEN(
        "Suttle running time is 1, interval time is 1, capacity is 1, "
        "one person waits at 23:59")
    {
        auto const n{1};
        auto const t{1};
        auto const m{5};
        std::vector<std::string> const time_table{"23:59"};

        WHEN("Calculate")
        {
            auto result_time{calculate_arrival_time(n, t, m, time_table)};

            THEN("The last time is 09:00")
            {
                auto const expected_time{"09:00"};
                REQUIRE(expected_time == result_time);
            }
        }
    }

    GIVEN(
        "Suttle running time is 10, interval time is 60, capacity is 45, "
        "all persons wait at 23:59")
    {
        auto const n{10};
        auto const t{60};
        auto const m{45};
        std::vector<std::string> const time_table{
            "23:59",
            "23:59",
            "23:59",
            "23:59",
            "23:59",
            "23:59",
            "23:59",
            "23:59",
            "23:59",
            "23:59",
            "23:59",
            "23:59",
            "23:59",
            "23:59",
            "23:59",
            "23:59"};

        WHEN("Calculate")
        {
            auto result_time{calculate_arrival_time(n, t, m, time_table)};

            THEN("The last time is 18:00")
            {
                auto const expected_time{"18:00"};
                REQUIRE(expected_time == result_time);
            }
        }
    }
}
