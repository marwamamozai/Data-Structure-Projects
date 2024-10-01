//test to see if works

#ifndef LINEAR_PROBING_HASH_TABLE_H
#define LINEAR_PROBING_HASH_TABLE_H

#include <vector>

class LinearProbingHashTable {
private:
    std::vector<int> table;

public:
    LinearProbingHashTable(int size) {
        table.resize(size);
    }
    void insert(int key) {
        int index = key % table.size();
        while (table[index] != 0) {
            index = (index + 1) % table.size();
        }
        table[index] = key;
    }
    bool search(int key) {
        int index = key % table.size();
        while (table[index] != 0) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % table.size();
        }
        return false;
    }
    void remove(int key) {
        int index = key % table.size();
        while (table[index] != 0) {
            if (table[index] == key) {
                table[index] = -1;
                return;
            }
            index = (index + 1) % table.size();
        }
    }
};

#endif /* LINEAR_PROBING_HASH_TABLE_H */
