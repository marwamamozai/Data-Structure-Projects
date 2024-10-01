// this is just atrial 
// main.cpp
#include "Search.h"
#include <iostream>
using namespace std;

int main() {
    // Example text and pattern
    string text = "This is a test text and it has a pattern within the text.";
    string pattern = "text";
    
    // Mock SuffixArray for the purpose of demonstration (not actual suffix array)
    SuffixArray suffixArr = {23, 52, 0, 10, 30}; // Arbitrary example indices for demonstration
    
    // Call the search function
    vector<size_t> results = searchFor(pattern, text, suffixArr);
    
    // Print results
    cout << "Pattern found at indices: ";
    for (auto idx : results) {
        cout << idx << " ";
    }
    cout << endl;
    
    return 0;
}
