#pragma once

#include <set>
#include <string>


using Set = std::multiset<std::string>;


Set split_to_words(std::string const& str);
Set calculate_intersection(Set const& set1, Set const& set2);
Set calculate_union(Set const& set1, Set const& set2);
int jaccard_similarity(std::string const& str1, std::string const& str2);
