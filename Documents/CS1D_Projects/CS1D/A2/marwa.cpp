// new file this is assignment 2 
//copy the code that was provided in class on wed?
#include "bst.h"
#include <stddef.h>  // FOR NULL
#include <stdlib.h>	// FOR malloc, free 
#include <iostream>

using namespace std; 

void insert_into(struct Node** root, int value){
/* TODO:  implement this fucntion! */ 

	cout << "Entered insert_into ..." << endl; 
	Node *z = NULL: 		// this is the node that will potentially 
					 			// be created, with the value as the key

	Node *x = *root;		// node being compaired with z 
	Node *y = NULL;		// y will be parent of z


	while ( x != NULL) 	// decend until reaching a leaf 
	{

		y = x;

		if (value == x->value)
			return;

		if(value < x->value)
			x = x->left;
		else
			x = x->right;
	}// end while 


	z = new struct Node;
	z->value = value;
	z->left  = NULL;
	z->right = N ULL;

// write the rest.. figure it out and look at the y




}














