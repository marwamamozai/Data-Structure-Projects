#ifndef ROBIN_HOOD_HASH_TABLE_H
#define ROBIN_HOOD_HASH_TABLE_H

#include <utility>
#include <vector>

class RobinHoodHashTable {
private:
  std::vector<std::pair<int, int>> table;

public:
  RobinHoodHashTable(int size) { table.resize(size); }

  void insert(int key) {
    int index = key % table.size();
    int displacement = 0;
    while (table[index].first != 0) {
      if (table[index].second >= displacement) {
        table[index] = std::make_pair(key, displacement);
        key = table[index].first;
        displacement = table[index].second;
      }
      index = (index + 1) % table.size();
      displacement++;
    }
    table[index] = std::make_pair(key, displacement);
  }

  bool search(int key) {
    int index = key % table.size();
    int displacement = 0;
    while (table[index].first != 0) {
      if (table[index].first == key) {
        return true;
      }
      if (table[index].second < displacement) {
        return false;
      }
      index = (index + 1) % table.size();
      displacement++;
    }
    return false;
  }

  void remove(int key) {
    int index = key % table.size();
    int displacement = 0;
    while (table[index].first != 0) {
      if (table[index].first == key) {
        table[index] = std::make_pair(0, 0);
        return;
      }
      if (table[index].second < displacement) {
        return;
      }
      index = (index + 1) % table.size();
      displacement++;
    }
  }
};

#endif /* ROBIN_HOOD_HASH_TABLE_H */
//test it

