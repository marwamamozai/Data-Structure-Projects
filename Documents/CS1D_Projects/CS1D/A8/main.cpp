//try to
#include "CardinalityEstimator.h"
#include "CuckooHashTable.h"
#include "LinearProbingHashTable.h"
#include "RobinHoodHashTable.h"
#include <chrono>
#include <iostream>
#include <vector>

int main() {
  // Common keys for all hash table operations
  std::vector<int> keys = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

  // --------------------
  // Cardinality Estimator
  // --------------------
  CardinalityEstimator cardinalityEstimator(10);
  auto start = std::chrono::high_resolution_clock::now();
  for (int key : keys) {
    cardinalityEstimator.see(key);
  }
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
  std::cout << "Time taken for Cardinality Estimator 'see' operations: "
            << duration.count() << " nanoseconds" << std::endl;
  int estimate = cardinalityEstimator.estimate();
  std::cout << "Cardinality Estimate: " << estimate << std::endl;

  // --------------------
  // Linear Probing Hash Table
  // --------------------
  LinearProbingHashTable lpHashTable(100);
  start = std::chrono::high_resolution_clock::now();
  for (int key : keys) {
    lpHashTable.insert(key);
  }
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
  std::cout << "Time taken for Linear Probing Hash Table insertions: "
            << duration.count() << " nanoseconds" << std::endl;

  // --------------------
  // Robin Hood Hash Table
  // --------------------
  RobinHoodHashTable rhHashTable(100);
  start = std::chrono::high_resolution_clock::now();
  for (int key : keys) {
    rhHashTable.insert(key);
  }
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
  std::cout << "Time taken for Robin Hood Hash Table insertions: "
            << duration.count() << " nanoseconds" << std::endl;

  // --------------------
  // Cuckoo Hash Table
  // --------------------
  CuckooHashTable cuckooHashTable(100);
  start = std::chrono::high_resolution_clock::now();
  for (int key : keys) {
    cuckooHashTable.insert(key);
  }
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
  std::cout << "Time taken for Cuckoo Hash Table insertions: "
            << duration.count() << " nanoseconds" << std::endl;

  return 0;
}

