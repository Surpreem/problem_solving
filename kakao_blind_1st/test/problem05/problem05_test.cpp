#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "problem05/problem05.h"


SCENARIO(
    "Split a string "
    "to the lowercase words of adjacent two characters",
    "[problem05]")
{
    GIVEN("String FR")
    {
        auto const str{"FR"};

        WHEN("Split the string")
        {
            auto result_words{split_to_words(str)};

            THEN("The set is fr")
            {
                Set const expected_words{"fr"};
                REQUIRE(expected_words.size() == result_words.size());

                for (auto iter{expected_words.begin()};
                    expected_words.end() != iter;
                    iter = expected_words.upper_bound(*iter)) {
                    REQUIRE(expected_words.count(*iter)
                        == result_words.count(*iter));
                }
            }
        }
    }

    GIVEN("String FRA")
    {
        auto const str{"FRA"};

        WHEN("Split the string")
        {
            auto result_words{split_to_words(str)};

            THEN("The set is fr, ra")
            {
                Set const expected_words{"fr", "ra"};
                REQUIRE(expected_words.size() == result_words.size());

                for (auto iter{expected_words.begin()};
                    expected_words.end() != iter;
                    iter = expected_words.upper_bound(*iter)) {
                    REQUIRE(expected_words.count(*iter)
                        == result_words.count(*iter));
                }
            }
        }
    }

    GIVEN("String AB+C")
    {
        auto const str{"AB+C"};

        WHEN("Split the string")
        {
            auto result_words{split_to_words(str)};

            THEN("The set is ab")
            {
                Set const expected_words{"ab"};
                REQUIRE(expected_words.size() == result_words.size());

                for (auto iter{expected_words.begin()};
                    expected_words.end() != iter;
                    iter = expected_words.upper_bound(*iter)) {
                    REQUIRE(expected_words.count(*iter)
                        == result_words.count(*iter));
                }
            }
        }
    }
}

SCENARIO("Calculate the intersection", "[problem05]")
{
    GIVEN("Set1 is {fr}, Set2 is {fr}")
    {
        Set const set1{"fr"};
        Set const set2{"fr"};

        WHEN("Calculate")
        {
            auto const result_intersection{calculate_intersection(set1, set2)};

            THEN("The intersection is {fr}")
            {
                Set const expected_intersection{"fr"};
                REQUIRE(expected_intersection.size()
                    == result_intersection.size());

                for (auto iter{expected_intersection.begin()};
                    expected_intersection.end() != iter;
                    iter = expected_intersection.upper_bound(*iter)) {
                    REQUIRE(expected_intersection.count(*iter)
                        == result_intersection.count(*iter));
                }
            }
        }
    }

    GIVEN("Set1 is {fr, fr, ra}, Set2 is {fr, ra, ca}")
    {
        Set const set1{"fr", "fr", "ra"};
        Set const set2{"fr", "ra", "ca"};

        WHEN("Calculate")
        {
            auto const result_intersection{calculate_intersection(set1, set2)};

            THEN("The intersection is {fr, ra}")
            {
                Set const expected_intersection{"fr", "ra"};
                REQUIRE(expected_intersection.size()
                    == result_intersection.size());

                for (auto iter{expected_intersection.begin()};
                    expected_intersection.end() != iter;
                    iter = expected_intersection.upper_bound(*iter)) {
                    REQUIRE(expected_intersection.count(*iter)
                        == result_intersection.count(*iter));
                }
            }
        }
    }
}

SCENARIO("Calculate the union", "[problem05]")
{
    GIVEN("Set1 is {fr}, Set2 is {fr}")
    {
        Set const set1{"fr"};
        Set const set2{"fr"};

        WHEN("Calculate")
        {
            auto const result_union{calculate_union(set1, set2)};

            THEN("The union is {fr}")
            {
                Set const expected_union{"fr"};
                REQUIRE(expected_union.size()
                    == result_union.size());

                for (auto iter{expected_union.begin()};
                    expected_union.end() != iter;
                    iter = expected_union.upper_bound(*iter)) {
                    REQUIRE(expected_union.count(*iter)
                        == result_union.count(*iter));
                }
            }
        }
    }

    GIVEN("Set1 is {fr, fr, ra}, Set2 is {fr, ra, ca}")
    {
        Set const set1{"fr", "fr", "ra"};
        Set const set2{"fr", "ra", "ca"};

        WHEN("Calculate")
        {
            auto const result_union{calculate_intersection(set1, set2)};

            THEN("The union is {ca, fr, fr, ra}")
            {
                Set const expected_union{"fr", "ra"};
                REQUIRE(expected_union.size()
                    == result_union.size());

                for (auto iter{expected_union.begin()};
                    expected_union.end() != iter;
                    iter = expected_union.upper_bound(*iter)) {
                    REQUIRE(expected_union.count(*iter)
                        == result_union.count(*iter));
                }
            }
        }
    }
}

SCENARIO("Calculate the Jaccard similarity", "[problem05]")
{
    GIVEN("Str1 is FRANCE, Str2 is french")
    {
        auto const str1{"FRANCE"};
        auto const str2{"french"};

        WHEN("Calculate")
        {
            auto result{jaccard_similarity(str1, str2)};

            THEN("The similarity is 16384")
            {
                auto const expected{16384};
                REQUIRE(expected == result);
            }
        }
    }

    GIVEN("Str1 is handshake, Str2 is shake hands")
    {
        auto const str1{"handshake"};
        auto const str2{"shake hands"};

        WHEN("Calculate")
        {
            auto result{jaccard_similarity(str1, str2)};

            THEN("The similarity is 65536")
            {
                auto const expected{65536};
                REQUIRE(expected == result);
            }
        }
    }

    GIVEN("Str1 is aa1+aa2, Str2 is AAAA12")
    {
        auto const str1{"aa1+aa2"};
        auto const str2{"AAAA12"};

        WHEN("Calculate")
        {
            auto result{jaccard_similarity(str1, str2)};

            THEN("The similarity is 43690")
            {
                auto const expected{43690};
                REQUIRE(expected == result);
            }
        }
    }

    GIVEN("Str1 is E=M*C^2, Str2 is e=m*c^2")
    {
        auto const str1{"E=M*C^2"};
        auto const str2{"e=m*c^2"};

        WHEN("Calculate")
        {
            auto result{jaccard_similarity(str1, str2)};

            THEN("The similarity is 65536")
            {
                auto const expected{65536};
                REQUIRE(expected == result);
            }
        }
    }
}
