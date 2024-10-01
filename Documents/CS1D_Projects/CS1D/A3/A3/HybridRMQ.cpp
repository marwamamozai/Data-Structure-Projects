#include "HybridRMQ.h"
#include <cmath>
#include <algorithm>


//constructor
HybridRMQ::HybridRMQ(const RMQEntry* elems, std::size_t numElems) {
}


//destrcutor
HybridRMQ::~HybridRMQ() {
}


//function 

std::size_t HybridRMQ::rmq(std::size_t low, std::size_t high) const {
    // rmq implementation
    // initialize the result as the first index in range
    std::size_t result = low;
    
    for (std::size_t i = low + 1; i < high; ++i) {
        if (elems[i] < elems[result]) {
            result = i;
        } // end if 
    }//end for
    
    return result;
}// end fucntion
