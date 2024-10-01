#include "PrecomputedRMQ.h"


//constructor 
PrecomputedRMQ::PrecomputedRMQ(const RMQEntry* elems, std::size_t numElems) {
  //void elems;
  //void numElems;


	std::size_t n = numElems;
	rmqTable.resize(n,std::vector<std::size_t>(n));

	for(std::size_t i = 0; i < n; ++i){
		for(std::size_t j = i; j< n; ++j){
			if( i == j){
				rmqTable[i][j] = i; 
			}else{
				rmqTable[i][j] = (elems[rmqTable[i][j-1]] <= elems[j]) ? rmqTable[i][j-1] :j;
					}//end else
			}//end for 
		}//end for 

} //end fucntion








PrecomputedRMQ::~PrecomputedRMQ() {
  //  nothing to deallocate 
}




std::size_t PrecomputedRMQ::rmq(std::size_t low, std::size_t high) const {

	std::size_t minIndex = low; 
	for (std:: size_t i = low + 1; i < high; ++i) { //size is set low + 1, if i is less than high keep ++
		if(elems[i] < elems[minIndex]){
			minIndex = i;
		}// emd if 
	}//end for 

	return minIndex; 
  //(void) low;
  //(void) high;
}// end fucntion
