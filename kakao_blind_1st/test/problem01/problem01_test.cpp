#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "problem01/problem01.h"


SCENARIO("Decrypting a secret map", "[problem01]")
{
    GIVEN("Map size is one by one, and only wall")
    {
        auto n{1};
        std::vector<int> arr1{1};
        std::vector<int> arr2{1};

        REQUIRE(n == arr1.size());
        REQUIRE(n == arr2.size());

        WHEN("Decryping")
        {
            auto result_map{decypting_map(n, arr1, arr2)};

            THEN("Result map size is one, and only wall")
            {
                std::vector<std::string> const expected_map{"#"};
                REQUIRE(n == result_map.size());
                REQUIRE(expected_map == result_map);
            }
        }
    }

    GIVEN("Map size is one by one, and only space")
    {
        auto n{1};
        std::vector<int> arr1{0};
        std::vector<int> arr2{0};

        REQUIRE(n == arr1.size());
        REQUIRE(n == arr2.size());

        WHEN("Decryping")
        {
            auto result_map{decypting_map(n, arr1, arr2)};

            THEN("Result map size is one, and only space")
            {
                std::vector<std::string> const expected_map{" "};
                REQUIRE(n == result_map.size());
                REQUIRE(expected_map == result_map);
            }
        }
    }

    GIVEN(
        "Map size is one by one, "
        "and one has space only and the other has wall only")
    {
        auto n{1};
        std::vector<int> arr1{0};
        std::vector<int> arr2{1};

        REQUIRE(n == arr1.size());
        REQUIRE(n == arr2.size());

        WHEN("Decryping")
        {
            auto result_map{decypting_map(n, arr1, arr2)};

            THEN("Result map size is one, and only wall")
            {
                std::vector<std::string> const expected_map{"#"};
                REQUIRE(n == result_map.size());
                REQUIRE(expected_map == result_map);
            }
        }
    }

    GIVEN("Map size is two by two")
    {
        auto n{2};
        std::vector<int> arr1{1, 3};
        std::vector<int> arr2{0, 0};

        REQUIRE(n == arr1.size());
        REQUIRE(n == arr2.size());

        WHEN("Decryping")
        {
            auto result_map{decypting_map(n, arr1, arr2)};

            THEN("Result map size is two, and only wall")
            {
                std::vector<std::string> const expected_map{" #", "##"};
                REQUIRE(n == result_map.size());
                REQUIRE(expected_map == result_map);
            }
        }
    }

    GIVEN("Map size is five by five")
    {
        auto n{5};
        std::vector<int> arr1{9, 20, 28, 18, 11};
        std::vector<int> arr2{30, 1, 21, 17, 28};

        REQUIRE(n == arr1.size());
        REQUIRE(n == arr2.size());

        WHEN("Decryping")
        {
            auto result_map{decypting_map(n, arr1, arr2)};

            THEN("Result map size is two, and only wall")
            {
                std::vector<std::string> const expected_map{
                    "#####", "# # #", "### #", "#  ##", "#####"};
                REQUIRE(n == result_map.size());
                REQUIRE(expected_map == result_map);
            }
        }
    }

    GIVEN("Map size is six by six")
    {
        auto n{6};
        std::vector<int> arr1{46, 33, 33, 22, 31, 50};
        std::vector<int> arr2{27, 56, 19, 14, 14, 10};

        REQUIRE(n == arr1.size());
        REQUIRE(n == arr2.size());

        WHEN("Decryping")
        {
            auto result_map{decypting_map(n, arr1, arr2)};

            THEN("Result map size is two, and only wall")
            {
                std::vector<std::string> const expected_map{
                    "######",
                    "###  #",
                    "##  ##",
                    " #### ",
                    " #####",
                    "### # "};
                REQUIRE(n == result_map.size());
                REQUIRE(expected_map == result_map);
            }
        }
    }
}
