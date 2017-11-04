#pragma once

#include <vector>


std::vector<char> set_up_board(std::vector<std::string> const& board);
std::vector<int> find_block(
    std::vector<char> const& board, int const width, int const height);
void erase_block(
    std::vector<int> const& back_board, std::vector<char>& front_board);
void move_block(
    std::vector<char>& front_board, int const width, int const height);
int erased_block_count(
    std::vector<std::string> const& board,
    int const width,
    int const height);
