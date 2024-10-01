#include "bst.h"
#include <stddef.h>  // For NULL
#include <stdlib.h>  // For malloc, free
using namespace std; 

void insert_into(struct Node** root, int value) {
	//(void) root;
	//(void) value;

	cout << "Entered insert_into..." << endl; //prompt that fucntion is being entered 

	Node *z = NULL;  // the node that will  potentially be created, w/ value as the key 
	Node *x = *root; // intialize pointer to the root and this node will be compaired to z 
	Node *y = NULL;  // initialize pointer to store the parent of z ( y will be parent of z)

	//Loop until reahcing a leaf or node with the matching value 
	while (x!= NULL){
		y = x; //update y to store the current node to x.... (!!!!!!!!)

		if(value == x-> value)// If the value is eqaul to the node its pointing to (in the tree), 
			return;			    // return w/o inserting anything 

		if(value < x-> value) // if the value is less than the value of the current node its pointing to
			x = x->left;		 // move to the left child,

		else //else move to the right child
			x = x->right;
	}// end while 

	// create a new node w/ specified value and left & right children w/ NULL // same var
	z = new struct Node;
	z->value = value; 
	z->left  = NULL;
	z->right = NULL;

	// new node is going ot be child of parent so set it as that 
	if(y == NULL) //if empty then make it as the root (this is the new node) 
		*root = z;
	else if(value < y->value) //if the val is less than parent val then set the node as left child
		y->left = z; 
	else // else set the new node as the right child 
		y->right = z;

}//end insert_into function



void free_tree(struct Node* root) {
	//(void) root; // silence parameter so u can run

	//OG case (base case) stop recursion if the root is equal to NULL
	if(root == NULL) 
		return;

	//recursivley free the left subtree aka left child 
	free_tree(root->left);

	//do the same thing for the right^
	free_tree(root->right);

	//delete the memory for the allocated current node
	delete root;

} // end the free_tree function 









size_t size_of(const struct Node* root) {
	/* TODO: Implement this function! */
	//(void) root;

	//If the root is NULL (size is empty ) so return 0
	if(root == NULL)
		return 0;

	// Recursively calc the size of the left subtree 
	size_t left_size = size_of(root->left);

   // Recursively calculate the size of the right subtree
   size_t right_size = size_of(root->right);

	// the size of the tree is the elft subtree and the right sub tree + 1 because of the root of the node
   return left_size + right_size + 1;
}









int* contents_of(const struct Node* root) {
	//(void) root;

	size_t tree_size = size_of(root); // count the num of nodes in the tree

	//allocate mem for array to store contents of the tree
	//make memoery for the array to put teh contents of the tree inside
	int* tree_contents = new int[tree_size];


	//initialize index to keep track of current postion in array 
	size_t index = 0;

	//call traverse to move the tree inorder (left root right) to fill arrat 
	//with sorted elements 
	inorder_traversal(root, tree_contents, index);




	return tree_contents;
}

//inorder traversal

void inorder_traversal(const Node* root, int* tree_contents, size_t &index){

	if(root == nullptr){
		return; //this is the base case
	}

	//start by traversing the left subtree 
	inorder_traversal(root->left,tree_contents,index);

	//go to the current node then add its value into the array 
	tree_contents[index++] = root -> value; 

	//traverse the right subtree too
	inorder_traversal(root->right,tree_contents, index);

}








const struct Node* second_min_in(const struct Node* root) {
	//(void) root;

	//intital pointer to NULL to keep track of 2nd smallest element 
	const struct Node* second_min = NULL;

	//if the root and left child is = to NULL return NULL (base case)
	if (root == NULL || root->left == NULL)
		return NULL;

	//Traverse left side until we reach a leaf nodeeee
	const struct Node* current = root; //set current node to root 

	//while(current->left != NULL){

		// if the left child of the current node you are on has no left kid itself
		//then the current node is the parent of the second smallest element int the tree 
		//if(current->left->left == NULL) {
		//	second_min = current; // set the current to the second smallest element ^
		//	break;

		if(size_of(root) < 2)
		{
			return NULL;
		}

		if(size_of(root-> left) > 1)
		{
			return second_min_in(root->left);
		}

		if(size_of(root->left) == 1)
		{
			return root;
		}

		return root;


	//	}// end the if 
	//}//end while 


	// return the sec small element
//	return second_min; 


}//end function
