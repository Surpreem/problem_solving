#include "problem05.h"

#include <cctype>
#include <algorithm>
#include <iterator>


Set split_to_words(std::string const& str)
{
    auto input_str{str};
    std::transform(
        input_str.begin(),
        input_str.end(),
        input_str.begin(),
        [](char const& c) {return static_cast<char>(::tolower(c)); });

    Set words;
    std::string word;
    auto previous_char{' '};
    for (auto c : input_str) {
        if (isalpha(previous_char) && isalpha(c)) {
            word = previous_char;
            word += c;
            words.emplace(word);
        }
        previous_char = c;
    }
    return words;
}

Set calculate_intersection(Set const& set1, Set const& set2)
{
    Set intersection;

    for (auto iter{set1.begin()};
        set1.end() != iter; iter = set1.upper_bound(*iter)) {
        auto const set1_elem_count{set1.count(*iter)};
        auto const set2_elem_count{set2.count(*iter)};
        if (set1_elem_count <= set2_elem_count)
            intersection.insert(iter, set1.upper_bound(*iter));
        else
            intersection.insert(set2.lower_bound(*iter), set2.upper_bound(*iter));
    }
    return intersection;
}

Set calculate_union(Set const& set1, Set const& set2)
{
    Set union_set;
    auto s2{set2};
    for (auto iter{set1.begin()};
        set1.end() != iter; iter = set1.upper_bound(*iter)) {
        auto const set1_elem_count{set1.count(*iter)};
        auto const set2_elem_count{s2.count(*iter)};
        if (set1_elem_count >= set2_elem_count)
            union_set.insert(iter, set1.upper_bound(*iter));
        else
            union_set.insert(s2.lower_bound(*iter), s2.upper_bound(*iter));

        s2.erase(*iter);
    }

    for (auto iter{s2.begin()}; s2.end() != iter; iter = s2.upper_bound(*iter))
        union_set.insert(iter, s2.upper_bound(*iter));

    return union_set;
}

int jaccard_similarity(std::string const& str1, std::string const& str2)
{
    auto const set1{split_to_words(str1)};
    auto const set2{split_to_words(str2)};

    /*Set intersection_set;
    std::set_intersection(
        set1.begin(),
        set1.end(),
        set2.begin(),
        set2.end(),
        std::inserter(intersection_set, intersection_set.begin()));*/
    auto const intersection_set{calculate_intersection(set1, set2)};

    /*Set union_set;
    std::set_union(
        set1.begin(),
        set1.end(),
        set2.begin(),
        set2.end(),
        std::inserter(union_set, union_set.begin()));*/
    auto const union_set{calculate_union(set1, set2)};

    auto const intersection_size{static_cast<double>(intersection_set.size())};
    auto const union_size{static_cast<double>(union_set.size())};
    double const similarity =
        intersection_size && union_size ? intersection_size / union_size : 1;
    return static_cast<int>(similarity * 65536);
}
