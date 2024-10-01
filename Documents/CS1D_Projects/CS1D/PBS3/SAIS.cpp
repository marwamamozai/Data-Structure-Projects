#include "SAIS.h"
#include <algorithm>
#include <vector>

const int ALPHABET_SIZE = 256;
const int S_TYPE = 0;
const int L_TYPE = 1;

bool compareSuffix(const Suffix &a, const Suffix &b) {
  return (a.rank[0] != b.rank[0]) ? (a.rank[0] < b.rank[0])
                                  : (a.rank[1] < b.rank[1]);
}

void updateRanksAndClassify(const std::vector<std::size_t> &text,
                            std::vector<Suffix> &suffixes,
                            std::vector<std::size_t> &suffixArray,
                            std::vector<int> &type, std::size_t n,
                            std::size_t k) {
  std::vector<std::size_t> tempIndex(n, 0); // Temp index
  suffixes[0].rank[1] = 0;

  for (std::size_t i = 1; i < n; i++) {
    suffixes[i].rank[0] = (suffixes[i].rank[0] == suffixes[i - 1].rank[0] &&
                           suffixes[i].rank[1] == suffixes[i - 1].rank[1])
                              ? suffixes[i - 1].rank[0]
                              : suffixes[i - 1].rank[0] + 1;
    tempIndex[suffixes[i].index] = i;
  }

  for (std::size_t i = 0; i < n; i++) {
    std::size_t nextIndex = suffixes[i].index + k / 2;
    suffixes[i].rank[1] =
        (nextIndex < n) ? suffixes[tempIndex[nextIndex]].rank[0] : 0;
    type[i] = (suffixes[i].rank[1] == 0) ? S_TYPE : L_TYPE;
  }

  for (std::size_t i = 0; i < n; i++) {
    suffixArray[i] = suffixes[i].index;
  }
}

void inducedSorting(const std::vector<std::size_t> &text,
                    std::vector<int> &type, std::vector<int> &suffixArray,
                    const std::vector<int> &lms_suffixes) {
  std::vector<int> bucketSizes(ALPHABET_SIZE, 0);
  std::vector<int> bucketEnds(ALPHABET_SIZE, 0);
  std::size_t n = text.size();

  for (std::size_t i = 0; i < n; i++) {
    bucketSizes[text[i]]++;
  }

  for (int i = 1; i < ALPHABET_SIZE; i++) {
    bucketEnds[i] = bucketEnds[i - 1] + bucketSizes[i - 1];
  }

  for (int lms_suffix : lms_suffixes) {
    suffixArray[bucketEnds[text[lms_suffix]]] = lms_suffix;
    bucketEnds[text[lms_suffix]]++;
  }

  for (std::size_t i = 0; i < n; i++) {
    if (suffixArray[i] > 0 && type[suffixArray[i] - 1] == L_TYPE) {
      suffixArray[bucketEnds[text[suffixArray[i] - 1]]] = suffixArray[i] - 1;
      bucketEnds[text[suffixArray[i] - 1]]++;
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    if (suffixArray[i] > 0 && type[suffixArray[i] - 1] == S_TYPE) {
      suffixArray[bucketEnds[text[suffixArray[i] - 1]] - 1] =
          suffixArray[i] - 1;
      bucketEnds[text[suffixArray[i] - 1]]--;
    }
  }
}

void inducedSorting(const std::vector<std::size_t> &text,
                    std::vector<int> &type, std::vector<int> &suffixArray,
                    const std::vector<int> &lms_suffixes);

std::vector<std::size_t> sais(const std::vector<std::size_t> &text) {
  std::size_t n = text.size();
  std::vector<std::size_t> suffixArray(n, 0);
  std::vector<Suffix> suffixes(n);
  std::vector<int> type(n);
  std::size_t k = 0;

  for (std::size_t i = 0; i < n; i++) {
    suffixes[i].index = i;
    suffixes[i].rank[0] = text[i];
    suffixes[i].rank[1] = (i + 1 < n) ? text[i + 1] : 0;
    k = std::max(k, suffixes[i].rank[0]);
  }

  std::sort(suffixes.begin(), suffixes.end(), compareSuffix);

  updateRanksAndClassify(text, suffixes, suffixArray, type, n, k);

  std::vector<int> lms_suffixes;
  for (std::size_t i = 1; i < n; i++) {
    if (type[i - 1] == L_TYPE && type[i] == S_TYPE) {
      lms_suffixes.push_back(i);
    }
  }

 // inducedSorting(text, type, suffixArray, lms_suffixes);
  // doesnt work when I call this fucntion 
  return suffixArray;
}
