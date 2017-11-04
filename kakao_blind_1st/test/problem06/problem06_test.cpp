#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "problem06/problem06.h"


SCENARIO("Set up a board", "[problem06]")
{
    GIVEN("3*3 board information")
    {
        auto const m{3};
        auto const n{3};
        std::vector<std::string> const board{"CCB", "AAA", "AAA"};

        REQUIRE(m == board.size());
        for (auto const& line : board)
            REQUIRE(n == line.size());

        WHEN("Set up the board")
        {
            auto result_board{set_up_board(board)};

            THEN("Result board is 3 * 3")
            {
                std::vector<char> const expected_board{
                    'C', 'C', 'B',
                    'A', 'A', 'A',
                    'A', 'A', 'A'};
                REQUIRE(expected_board.size() == result_board.size());

                for (auto i{0}; expected_board.size() != i; ++i)
                    REQUIRE(expected_board.at(i) == result_board.at(i));
            }
        }
    }
}

SCENARIO("Find all 2*2 blocks", "[problem06]")
{
    GIVEN("3*3 board information")
    {
        auto const m{3};
        auto const n{3};
        std::vector<char> const board{
            'C', 'C', 'B',
            'A', 'A', 'A',
            'A', 'A', 'A'};

        REQUIRE(m * n== board.size());

        WHEN("Find the blocks")
        {
            auto result_board{find_block(board, n, m)};

            THEN("The cell with 0 will be deleted")
            {
                std::vector<int> const expected_board{
                    1, 1, 1,
                    0, 0, 0,
                    0, 0, 0};
                REQUIRE(expected_board.size() == result_board.size());

                for (auto i{0}; expected_board.size() != i; ++i)
                    REQUIRE(expected_board.at(i) == result_board.at(i));
            }
        }
    }

    GIVEN("3*3 board information")
    {
        auto const m{3};
        auto const n{3};
        std::vector<char> const board{
            'C', 'A', 'A',
            'A', 'A', 'A',
            'A', 'A', 'D'};

        REQUIRE(m * n == board.size());

        WHEN("Find the blocks")
        {
            auto result_board{find_block(board, n, m)};

            THEN("The cell with 0 will be deleted")
            {
                std::vector<int> const expected_board{
                    1, 0, 0,
                    0, 0, 0,
                    0, 0, 1};
                REQUIRE(expected_board.size() == result_board.size());

                for (auto i{0}; expected_board.size() != i; ++i)
                    REQUIRE(expected_board.at(i) == result_board.at(i));
            }
        }
    }
}

SCENARIO("Erase blocks", "[problem06]")
{
    GIVEN("3*3 board information")
    {
        std::vector<char> front_board{
            'C', 'C', 'B',
            'A', 'A', 'A',
            'A', 'A', 'A'};

        std::vector<int> const back_board{
            1, 1, 1,
            0, 0, 0,
            0, 0, 0};

        WHEN("Erase the blocks")
        {
            erase_block(back_board, front_board);

            THEN("The deleted cell has a blank")
            {
                std::vector<char> const expected_board{
                    'C', 'C', 'B',
                    ' ', ' ', ' ',
                    ' ', ' ', ' '};
                REQUIRE(expected_board.size() == front_board.size());

                for (auto i{0}; expected_board.size() != i; ++i)
                    REQUIRE(expected_board.at(i) == front_board.at(i));
            }
        }
    }
}

SCENARIO("Move blocks", "[problem06]")
{
    GIVEN("3*3 board information")
    {
        auto const m{3};
        auto const n{3};
        std::vector<char> front_board{
            'C', 'C', 'B',
            ' ', ' ', ' ',
            ' ', ' ', ' '};

        WHEN("Move the blocks")
        {
            move_block(front_board, n, m);

            THEN("Rearrange the boards")
            {
                std::vector<char> const expected_front_board{
                    ' ', ' ', ' ',
                    ' ', ' ', ' ',
                    'C', 'C', 'B'};
                REQUIRE(expected_front_board.size() == front_board.size());

                for (auto i{0}; expected_front_board.size() != i; ++i)
                    REQUIRE(expected_front_board.at(i) == front_board.at(i));
            }
        }
    }

    GIVEN("3*3 board information")
    {
        auto const m{3};
        auto const n{3};
        std::vector<char> front_board{
            'C', ' ', ' ',
            ' ', ' ', ' ',
            ' ', ' ', 'D'};

        WHEN("Move the blocks")
        {
            move_block(front_board, n, m);

            THEN("Rearrange the boards")
            {
                std::vector<char> const expected_front_board{
                    ' ', ' ', ' ',
                    ' ', ' ', ' ',
                    'C', ' ', 'D'};
                REQUIRE(expected_front_board.size() == front_board.size());

                for (auto i{0}; expected_front_board.size() != i; ++i)
                    REQUIRE(expected_front_board.at(i) == front_board.at(i));
            }
        }
    }
}

SCENARIO("Calculate the erased blocks", "[problem06]")
{
    GIVEN("3*3 board information")
    {
        auto const m{3};
        auto const n{3};
        std::vector<std::string> const board{"CCB", "AAA", "AAA"};

        WHEN("Calculate")
        {
            auto result{erased_block_count(board, n, m)};

            THEN("6 blocks was erased")
            {
                REQUIRE(6 == result);
            }
        }
    }

    GIVEN("3*3 board information")
    {
        auto const m{4};
        auto const n{5};
        std::vector<std::string> const board{
            "CCBDE", "AAADE", "AAABF", "CCBBF"};

        WHEN("Calculate")
        {
            auto result{erased_block_count(board, n, m)};

            THEN("14 blocks was erased")
            {
                REQUIRE(14 == result);
            }
        }
    }

    GIVEN("6*6 board information")
    {
        auto const m{6};
        auto const n{6};
        std::vector<std::string> const board{
            "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};

        WHEN("Calculate")
        {
            auto result{erased_block_count(board, n, m)};

            THEN("15 blocks was erased")
            {
                REQUIRE(15 == result);
            }
        }
    }
}
