#include "FastestRMQ.h"
#include <cmath> // for std::log2
#include <algorithm> // for std::min

FastestRMQ::FastestRMQ(const RMQEntry* elems, std::size_t numElems)
    : elems(elems), numElems(numElems) {
    // Preprocess the input array if necessary
}

FastestRMQ::~FastestRMQ() {
    // No cleanup needed as there is no dynamic memory allocation
}

std::size_t FastestRMQ::rmq(std::size_t low, std::size_t high) const {
    // Perform RMQ query over the specified range
    std::size_t minIndex = low;
    for (std::size_t i = low + 1; i < high; ++i) {
        if (elems[i].value() < elems[minIndex].value()) {
            minIndex = i;
        }
    }
    return minIndex;
}
