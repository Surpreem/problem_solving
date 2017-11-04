#include "problem02.h"

#include <array>
#include <cctype>
#include <cmath>
#include <numeric>


int dart_score(std::string const& dart_result)
{
    std::array<int, 4> score{0};
    auto trial{1};
    auto previous_char{'0'};
    for (auto const& ch : dart_result) {
        if (isdigit(ch)) {
            if (!isdigit(previous_char))
                ++trial;

            score.at(trial) = score.at(trial) * 10 + ch - '0';
            continue;
        }

        if ('D' == ch)
            score.at(trial) = static_cast<int>(pow(score.at(trial), 2));
        else if ('T' == ch)
            score.at(trial) = static_cast<int>(pow(score.at(trial), 3));

        if ('*' == ch) {
            score.at(trial - 1) *= 2;
            score.at(trial) *= 2;
        } else if ('#' == ch) {
            score.at(trial) *= -1;
        }
        previous_char = ch;
    }

    return std::accumulate(score.cbegin(), score.cend(), 0);
}
