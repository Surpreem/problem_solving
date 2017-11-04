#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "problem03/problem03.h"


SCENARIO("Calculate a cache performance", "[problem03]")
{
    GIVEN("Cache size is 0, input one city")
    {
        auto const cache_size{1};
        std::vector<std::string> const city{"Jeju"};

        WHEN("Calculate")
        {
            auto result_time{cache_performace(cache_size, city)};

            THEN("Cache miss")
            {
                auto const expected_time{5};
                REQUIRE(expected_time == result_time);
            }
        }
    }

    GIVEN("Cache size is 1, input one city")
    {
        auto const cache_size{1};
        std::vector<std::string> const city{"Jeju"};

        WHEN("Calculate")
        {
            auto result_time{cache_performace(cache_size, city)};

            THEN("Cache miss")
            {
                auto const expected_time{5};
                REQUIRE(expected_time == result_time);
            }
        }
    }

    GIVEN("Cache size is 1, input two city")
    {
        auto const cache_size{1};
        std::vector<std::string> const city{"Jeju", "Jeju"};

        WHEN("Calculate")
        {
            auto result_time{cache_performace(cache_size, city)};

            THEN("Cache hit")
            {
                auto const expected_time{6};
                REQUIRE(expected_time == result_time);
            }
        }
    }

    GIVEN("Cache size is 1, input two city and case-insensitive")
    {
        auto const cache_size{1};
        std::vector<std::string> const city{"Jeju", "jeju"};

        WHEN("Calculate")
        {
            auto result_time{cache_performace(cache_size, city)};

            THEN("Cache hit")
            {
                auto const expected_time{6};
                REQUIRE(expected_time == result_time);
            }
        }
    }

    GIVEN("Cache size is 3, and case-insensitive")
    {
        auto const cache_size{3};
        std::vector<std::string> const city{
            "Jeju",
            "Pangyo",
            "Seoul",
            "NewYork",
            "LA",
            "Jeju",
            "Pangyo",
            "Seoul",
            "NewYork",
            "LA"};

        WHEN("Calculate")
        {
            auto result_time{cache_performace(cache_size, city)};

            THEN("Result is 50")
            {
                auto const expected_time{50};
                REQUIRE(expected_time == result_time);
            }
        }
    }

    GIVEN("Cache size is 2, and case-insensitive")
    {
        auto const cache_size{3};
        std::vector<std::string> const city{
            "Jeju",
            "Pangyo",
            "NewYork",
            "newyork"};

        WHEN("Calculate")
        {
            auto result_time{cache_performace(cache_size, city)};

            THEN("Result is 16")
            {
                auto const expected_time{16};
                REQUIRE(expected_time == result_time);
            }
        }
    }
}
