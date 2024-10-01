#include "Search.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<size_t> searchFor(const string& pattern, const string& text, const SuffixArray& suffixArr) {
    vector<size_t> matches;
    int m = pattern.size();
    int n = text.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = text.compare(suffixArr[mid], m, pattern);
        cout << "Low: " << low << ", High: " << high << ", Mid: " << mid << ", Cmp: " << cmp << endl;
        if (cmp < 0) {
            low = mid + 1;
        } else if (cmp > 0) {
            high = mid - 1;
        } else {
            matches.push_back(suffixArr[mid]); 
            for (int i = mid + 1; i < n && text.compare(suffixArr[i], m, pattern) == 0; ++i) {
                matches.push_back(suffixArr[i]);
            }
            for (int i = mid - 1; i >= 0 && text.compare(suffixArr[i], m, pattern) == 0; --i) {
                matches.push_back(suffixArr[i]);
            }
            break;
        }
    }
    sort(matches.begin(), matches.end());
    return matches;
}
