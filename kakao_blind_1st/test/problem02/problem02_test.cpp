#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "problem02/problem02.h"


SCENARIO("Calculate a dart score", "[problem02]")
{
    GIVEN("trial one time, given 1 point")
    {
        std::string const dart_result{"1"};

        WHEN("Calculate")
        {
            auto result_score{dart_score(dart_result)};

            THEN("Get score 1")
            {
                auto const expected_score{1};
                REQUIRE(expected_score == result_score);
            }
        }
    }

    GIVEN("trial one time, given 10 point")
    {
        std::string const dart_result{"10"};

        WHEN("Calculate")
        {
            auto result_score{dart_score(dart_result)};

            THEN("Get score 10")
            {
                auto const expected_score{10};
                REQUIRE(expected_score == result_score);
            }
        }
    }

    GIVEN("trial one time, given 3 point and Double")
    {
        std::string const dart_result{"3D"};

        WHEN("Calculate")
        {
            auto result_score{dart_score(dart_result)};

            THEN("Get score 9")
            {
                auto const expected_score{9};
                REQUIRE(expected_score == result_score);
            }
        }
    }

    GIVEN("trial one time, given 7 point and Triple")
    {
        std::string const dart_result{"7T"};

        WHEN("Calculate")
        {
            auto result_score{dart_score(dart_result)};

            THEN("Get score 343")
            {
                auto const expected_score{343};
                REQUIRE(expected_score == result_score);
            }
        }
    }

    GIVEN("trial one time, given 6 point and Double, *")
    {
        std::string const dart_result{"6D*"};

        WHEN("Calculate")
        {
            auto result_score{dart_score(dart_result)};

            THEN("Get score 72")
            {
                auto const expected_score{72};
                REQUIRE(expected_score == result_score);
            }
        }
    }

    GIVEN("trial one time, given 6 point and Double, #")
    {
        std::string const dart_result{"6D#"};

        WHEN("Calculate")
        {
            auto result_score{dart_score(dart_result)};

            THEN("Get score -36")
            {
                auto const expected_score{-36};
                REQUIRE(expected_score == result_score);
            }
        }
    }

    GIVEN("trial two times, given 6D7S*")
    {
        std::string const dart_result{"6D7S*"};

        WHEN("Calculate")
        {
            auto result_score{dart_score(dart_result)};

            THEN("Get score 86")
            {
                auto const expected_score{86};
                REQUIRE(expected_score == result_score);
            }
        }
    }

    GIVEN("trial three times, given 1S2D*3T")
    {
        std::string const dart_result{"1S2D*3T"};

        WHEN("Calculate")
        {
            auto result_score{dart_score(dart_result)};

            THEN("Get score 37")
            {
                auto const expected_score{37};
                REQUIRE(expected_score == result_score);
            }
        }
    }

    GIVEN("trial three times, given 1D#2S*3S")
    {
        std::string const dart_result{"1D#2S*3S"};

        WHEN("Calculate")
        {
            auto result_score{dart_score(dart_result)};

            THEN("Get score 5")
            {
                auto const expected_score{5};
                REQUIRE(expected_score == result_score);
            }
        }
    }

    GIVEN("trial three times, given 1T2D3D#")
    {
        std::string const dart_result{"1T2D3D#"};

        WHEN("Calculate")
        {
            auto result_score{dart_score(dart_result)};

            THEN("Get score -4")
            {
                auto const expected_score{-4};
                REQUIRE(expected_score == result_score);
            }
        }
    }
}
