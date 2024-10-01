#include "SparseTableRMQ.h"
#include <cmath> 
#include <algorithm>


//constructor 
SparseTableRMQ::SparseTableRMQ(const RMQEntry* elems, std::size_t numElems) {

	//initalize variables
	this ->elems = elems;
	this ->numElems = numElems;

	//precomputed sparse table
	std::size_t logn = std::log2(numElems) + 1; 
	SparseTableRMQ.resize(numElems,std::vector<std::size_t>(logn));


	//initializr the sparsetable
	    for (std::size_t i = 0; i < numElems; ++i) {
        sparseTable[i][0] = i;
    }// end for 


	//compute the values form previously computed values 
	   for (std::size_t j = 1; (1 << j) <= numElems; ++j) {
        for (std::size_t i = 0; i + (1 << j) - 1 < numElems; ++i) {
            if (elems[sparseTable[i][j - 1]] < elems[sparseTable[i + (1 << (j - 1))][j - 1]]) {
                sparseTable[i][j] = sparseTable[i][j - 1];
            } else {
                sparseTable[i][j] = sparseTable[i + (1 << (j - 1))][j - 1];
            }// else 
        }//end for 
    }// end for
}// constructor 



//destructor 
SparseTableRMQ::~SparseTableRMQ() {
	//nothing to deallocate 

}//end destrcutor 




std::size_t SparseTableRMQ::rmq(std::size_t low, std::size_t high) const {
    std::size_t k = std::log2(high - low + 1);
    if (elems[sparseTable[low][k]] < elems[sparseTable[high - (1 << k) + 1][k]]) {
        return SparseTableRMQ[low][k];
    } else {
        return SparseTableRMQ[high - (1 << k) + 1][k];
    }
}



/* Range Minimum Query
std::size_t SparseTableRMQ::rmq(std::size_t low, std::size_t high) const {
    std::size_t k = std::log2(high - low);
    if (elems[SparseTableRMQ[low][k]] < elems[SparseTableRMQ[high - (1 << k)][k]]) {
        return SparseTableRMQ[low][k];
    } else {
        return SparseTableRMQ[high - (1 << k)][k];
    }//end if 
}//end rmq
*/












