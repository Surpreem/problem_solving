#include "problem06.h"


constexpr auto blank_cell{' '};
constexpr auto erase_cell{0};
constexpr auto block_cell{1};


std::vector<char> set_up_board(std::vector<std::string> const& board)
{
    std::vector<char> result_board;
    for (auto const& line : board)
        for (auto const& cell : line)
            result_board.emplace_back(cell);

    return result_board;
}

std::vector<int> find_block(
    std::vector<char> const& board, int const width, int const height)
{
    std::vector<int> result_board;
    result_board.resize(width * height, block_cell);
    auto cell_position =
        [width](int const x, int const y) {return y * width + x;};

    auto const width_limit{width - 1};
    auto const height_limit{height - 1};
    for (auto y{0}; height_limit - 1 >= y; ++y)
        for (auto x{0}; width_limit - 1 >= x; ++x) {
            auto const block{board.at(cell_position(x, y))};
            if (blank_cell == block)
                continue;

            if (block == board.at(cell_position(x + 1, y))
                && block == board.at(cell_position(x + 1, y + 1))
                && block == board.at(cell_position(x, y + 1))) {

                result_board.at(cell_position(x, y)) = erase_cell;
                result_board.at(cell_position(x + 1, y)) = erase_cell;
                result_board.at(cell_position(x + 1, y + 1)) = erase_cell;
                result_board.at(cell_position(x, y + 1)) = erase_cell;
            }
        }

    return result_board;
}

void erase_block(
    std::vector<int> const& back_board, std::vector<char>& front_board)
{
    for (size_t i{0}; front_board.size() != i; ++i)
        if (erase_cell == back_board.at(i))
            front_board.at(i) = blank_cell;
}

void move_block(
    std::vector<char>& front_board, int const width, int const height)
{
    auto cell_position =
        [width](int const x, int const y) {return y * width + x;};

    auto const width_limit{width - 1};
    auto const height_limit{height - 1};
    for (auto y{height_limit - 1}; 0 <= y; --y)
        for (auto x{0}; width_limit >= x; ++x) {
            auto const src_block{front_board.at(cell_position(x, y))};
            if (blank_cell == src_block)
                continue;

            for (auto h{height_limit}; y < h; --h) {
                auto const dest_block{front_board.at(cell_position(x, h))};
                if (blank_cell == dest_block) {
                    front_board.at(cell_position(x, h)) = src_block;
                    front_board.at(cell_position(x, y)) = blank_cell;
                    break;
                }
            }
        }
}

int erased_block_count(
    std::vector<std::string> const& board,
    int const width,
    int const height)
{
    auto front_board{set_up_board(board)};
    while (true) {
        auto back_board{find_block(front_board, width, height)};
        erase_block(back_board, front_board);
        auto const iter{
            std::find(back_board.cbegin(), back_board.cend(), erase_cell)};
        if (back_board.end() == iter)
            break;

        move_block(front_board, width, height);
    }
    return static_cast<int>(
        std::count(front_board.begin(), front_board.end(), blank_cell));
}
