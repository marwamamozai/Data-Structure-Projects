#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include <vector>

typedef std::vector<size_t> SuffixArray;

std::vector<size_t> searchFor(const std::string &pattern,
                              const std::string &text,
                              const SuffixArray &suffixArr);

#endif // SEARCH_H
