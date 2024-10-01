#include <iostream>
#include <fstream> 
#include <cctype>
#include <string>
using namespace std;

// Function Declarations
void bubbleSort(int A[], int n);      // DONE (C)
void insertionSort(int A[], int n);   // DONE (A)
void heapSort (int A[], int n);		  // DONE (D)
void mergeSort(int A[], int n, int p, int r);	// DONE (B)
void quickSort(int A[],int p, int r);				// DONE (E)
int* countingSort(int A[], int n, int k );	   // DONE (F)
void radixSort(int A[], int n, int d);		  		// DONE (G)

//FUCNTIONS FOR OTHER FUCNTIONS 
int partition (int A[], int p , int r);
int LEFT(int i);
int RIGHT(int i);
void maxHeapify(int A[], int i , int heapSize);
void buildMaxHeap(int A[], int n);



//  PROGRAM CONCEPT 
  /* what do you want to do? I am going to make fucntions for  my program, then
   * i am going to call them  within the switch statement, have the fucntions
   * above my main then call them within the swtich statement */


// MAIN
int main(int argc, char* argv[]) {


    // Check if there are enough arguments
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <sorting_algorithm> <input_file>\n";
        return 1;
    }

    // Convert the first argument to an integer
    int sort = atoi(argv[1]);

  char sort;
  int  *array = nullptr;//A[]
  int  count = 0; //n
  int  value; 
	int p, r, k, d;

  cout << " what sort do you want to run ? : " << endl;
  cout << " A (Insertion Sort) " << endl; 
  cout << " B (Merge Sort) "     << endl; 
  cout << " C (Bubble Sort) "    << endl;
  cout << " D (Heap Sort) "      << endl;
  cout << " E (Quick Sort) "     << endl; 
  cout << " F (Counting Sort) "  << endl;
  cout << " G (Radix Sort) " 	   << endl;
  cin >> sort;

  sort = toupper(sort); //toupper function for sort 


/*
 //Will have fstream file here
	
 ifstream file("data.txt");
 
 if(!file){
 
 cerr << "Error: File is unable to open " << endl;
 return 1;

 }//end if 

 while (file >> value) { //while file has data inpt g increment the count
  count++;
 } //end while
 
 file.clear(); //Reset the file stream at ist og state
 file.seekg(0); // Move the file pointer back to the beg?
 
 array = new int[count]; //allocate the memory for dynamic array 
 
 int index = 0; 
 while (file >> value) {
 array[index++] = value; 
  }// end while 

 file.close(); 

*/ //end of file section 

 switch (sort)
 {

   case ('A'): { // insertion
    cout << " You've selected the Insertion Sort: " << endl;
    insertionSort(array,count);
   break;

   }

	case ('B'): {
    cout << " You've selected the Merge Sort: " << endl;
    mergeSort(array,count,p,r);
   break;

   }

   case ('C'): {
    cout << " You've selected the Bubble Sort: " << endl;
    bubbleSort(array,count);
   break;

   }

	case ('D'): {
    cout << " You've selected the Heap Sort: " << endl;
     heapSort(array,count);
   break;


   }

	case ('E'): {
    cout << " You've selected the Quick Sort: " << endl;
    quickSort(array,p,r);
   break;


   }

	case ('F'): {
    cout << " You've selected the Counting Sort: " << endl;
    countingSort(array,count,k);
   break;


   }

	case ('G'): {
    cout << " You've selected the Radix Sort: " << endl;
    radixSort(array,count,d); 
   break;

   }
   default:
    cout << "Invalid choice! Try again" << endl;


 } //end sort

 // Print array before and after 
 
 // Print the sorted  array 
 cout << " Sorted array: " ; 

 for ( int i = 0; i < count; ++i){
  cout << array[i] << " " ; 
 }// end for

 cout << endl; 
 
 //The deallocate memoery thatw as used for dyn array 
 delete[] array; 



  return 0;

}//end main




//FUNCTIONS

// BUBBLE SORT

void bubbleSort(int A[], int n) {

  for (int i = 0; i < n - 1; ++i) {

    for ( int j = n - 1; j > i ; --j){
      if (A[j] < A[j - 1]) {
        // swap A[j} and A[j-1]
        int temp = A[j];

        A[j] = A[j - 1];
        A[j - 1] = temp;

      } // end if
    } // end (for int j)
  }    // end (for int i)
} // end function

//------------------

// INSERTION SORT

void insertionSort(int A[], int n) {

  for (int j = 1; j < n; ++j) {
    int i = j - 1;
    int key = A[j];

    while (i >= 0 && A[i] > key) {
      A[i + 1] = A[i];
      --i;
    } // end while

    A[i + 1] = key;
  } // end for
} // end function

//----------------------


//MERGE SORT


void mergeSort(int A[], int n, int p, int r){	// (B)

	if (p < r) {
	int q = (p + r) / 2;
	int n_L = q - p + 1; //legth of A[p:q]
	int n_R = r - q; //legth of A[q+r:]


	//creat temp arr l and r
	int L[n_L], R[n_R];

	//copy data into temp array
	for (int i = 0; i < n_L; i++){
		L[i] = A [p + i];
	}
		for(int j =0; j< n_R; j++){
			R[j] = A[q + j+1];
		}	
			int i = 0; //smallest element in L remaining
			int j = 0; //^
			int k = p; // k indexes aew in location for A to fill

			//merge the two arrays
			while (i < n_L && j < n_R) {
				if(L[i] <= R[j]){
					A[k] = L[i];
					i++;
				}else{
					A[k] = R[j];
					j++; 
				}//end else 
				k++;
			}// end while 

			while (i < n_L){ //copy remaing elements
				A[k] = L[i];
				i++;
				k++;
			}//end while

			while (j < n_R){ //copy remaing elements
			A[k] = R [j];
				j++;
				k++;
			}//end while
		}// end if
		// recursivley call the merge sort 
		mergeSort(A, n, p, r);
		mergeSort(A, n, p + 1, r);

	}// function

//----------------------------

// PARTITION & QUICK SORT

int partition(int A[],int p, int r){

	int x = A[r]; //pivot
	int i = p - 1; // the highest index in the lower side

	for(int j =p; j <=r -1; j++){
		if(A[j] <= x) {
			i++;
			swap(A[i],A[j]);
		}//end if
	}// end for

	swap(A[i+1], A[r]);//pivot will go to the lowest side
	return i + 1;

 }// end function

void quickSort(int A[], int p, int r){

	if(p<r){
		int q = partition(A,p,r);
		quickSort(A,p,q-1); // recursively sort the lower  side
		quickSort(A,q+1,r); // recursively sort the higher side
	}//end if 

 } // end the function


//----------------------------

// COUNTING & RADIX SORT

int* countingSort(int A[], int n, int k){

	int* B = new int[n];
	int* C = new int[k+1]{0};

	for(int j = 0; j <n; j++){
		C[A[j]]++;
	}// end for

	for(int i = 1; i <= k; i++){
		C[i] += C[i-1];
	}

	for(int j = n -1; j >= 0; j--){
		B[C[A[j]]-1] = A[j];
		C[A[j]]--;
	}

	delete[] C;
	return B;
 }// end fucntion


void radixSort(int A[], int n, int d){

	for(int i = 1; i <= d; i++){

		int* sorted = countingSort(A,n,9);

		for ( int j = 0; j < n; j++){
			A[j] = sorted[j];
		}

		delete[] sorted;
	}// end for i 

 }//end function

//-------------------------------

// HEAP SORT ETC

int LEFT(int i) {
	return 2 * i;
 }//end function


int RIGHT(int i) {
	return 2 * i + 1;
 }//end function


void maxHeapify(int A[], int i, int heapSize){

	int l = LEFT(i);
	int r = RIGHT(i);
	int largest = i;

	if(l<= heapSize && A[l] > A[i])
		largest = l;

	if(r <= heapSize && A[r] > A[largest])
		largest = r;

	if(largest != i){
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		maxHeapify(A,largest,heapSize);
	}
 }// end function



void buildMaxHeap(int A[], int n){

	for(int i = n/2; i >= 1; i--)
		maxHeapify(A,i,n);
 }//end function


void heapSort(int A[], int n){

	buildMaxHeap(A,n);
	int heapSize = n;

	for(int i = n; i>= 2; i--){
		int temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		heapSize--;
		maxHeapify(A,1,heapSize);
	}
 }// end fucntion



