#ifndef CARDINALITY_ESTIMATOR_H
#define CARDINALITY_ESTIMATOR_H

#include <algorithm>
#include <vector>
class CardinalityEstimator {

	private:
   std::vector<int> seen;
   int k;

	public:
  	CardinalityEstimator(int k_val) : k(k_val) {}
  	void see(int x) {
    if (std::find(seen.begin(), seen.end(), x) == seen.end()) {
      seen.push_back(x);
    	}
  	}
   int estimate() {
   std::sort(seen.begin(), seen.end());
    if (seen.size() < k) {
      return 0;
    }
    return seen[k - 1];
  }
};

#endif /* CARDINALITY_ESTIMATOR_H */

//works 
