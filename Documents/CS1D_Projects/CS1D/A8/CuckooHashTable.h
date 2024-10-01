
//cuckOOhashtbale 

#ifndef CUCKOO_HASH_TABLE_H
#define CUCKOO_HASH_TABLE_H

#include <algorithm>  // for std::swap
#include <cmath>      // for pow
#include <functional> // for std::hash
#include <limits>     // for std::numeric_limits
#include <vector>

class CuckooHashTable {
private:
  std::vector<int> table1;
  std::vector<int> table2;
  std::hash<int> hasher;
  int maxIterations;

public:
  CuckooHashTable(int size) {
    table1.resize(size, std::numeric_limits<int>::min());
    table2.resize(size, std::numeric_limits<int>::min());
    maxIterations = log2(size) * 3; // Adjust as needed
  }

  void insert(int key) {
    int current_key = key;
    for (int i = 0; i < maxIterations; ++i) {
      int hash1 = hasher(current_key) % table1.size();
      int hash2 = (hasher(current_key) >> 16) %
                  table2.size(); // Using different bits for second hash

      if (table1[hash1] == key || table2[hash2] == key) {
        return; // Key already exists
      }

      if (table1[hash1] == std::numeric_limits<int>::min()) {
        table1[hash1] = current_key;
        return; // Successfully inserted
      } else if (table2[hash2] == std::numeric_limits<int>::min()) {
        table2[hash2] = current_key;
        return; // Successfully inserted
      } else {
        std::swap(current_key, (hasher(current_key) % 2 == 0) ? table1[hash1]
                                                              : table2[hash2]);
      }
    }

    // Failed to insert after maximum iterations, need to rehash or resize
    // Handle this according to your requirements
  }

  bool search(int key) {
    int hash1 = hasher(key) % table1.size();
    int hash2 = (hasher(key) >> 16) % table2.size();

    return (table1[hash1] == key || table2[hash2] == key);
  }

  void remove(int key) {
    int hash1 = hasher(key) % table1.size();
    int hash2 = (hasher(key) >> 16) % table2.size();

    if (table1[hash1] == key) {
      table1[hash1] = std::numeric_limits<int>::min();
    } else if (table2[hash2] == key) {
      table2[hash2] = std::numeric_limits<int>::min();
    }
  }
};

#endif /* CUCKOO_HASH_TABLE_H */

