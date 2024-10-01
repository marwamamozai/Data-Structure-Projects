#ifndef SAIS_H
#define SAIS_H

#include <vector>

struct Suffix {
  std::size_t index;
  std::size_t rank[2];
};

// Function to compare two suffixes
bool compareSuffix(const Suffix &a, const Suffix &b);

// Function to update ranks of the suffixes and classify them as S-type or
// L-type
void updateRanksAndClassify(const std::vector<std::size_t> &text,
                            std::vector<Suffix> &suffixes,
                            std::vector<std::size_t> &suffixArray,
                            std::vector<int> &type, std::size_t n,
                            std::size_t k);

// SAIS function
std::vector<std::size_t> sais(const std::vector<std::size_t> &text);

// Declaration for inducedSorting function
void inducedSorting(const std::vector<std::size_t> &text,
                    std::vector<int> &type, std::vector<int> &suffixArray,
                    const std::vector<int> &lms_suffixes);

#endif // SAIS_H

