/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows
 6
/ \
1  10

A BST is said to be balanced ,when it satisifes the following property

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but
right subtree height is 2
(Diff >1)

1
\
3
/ \
10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
#include<stdio.h>
#include<malloc.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
struct node* createNode(int value){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node* sortArray(int *arr, int firstIndex, int lastIndex){
	if (firstIndex > lastIndex)return NULL;
	int middle = firstIndex + (lastIndex-firstIndex) / 2;
	struct node *temp = createNode(arr[middle]);
	temp->left = sortArray(arr, firstIndex, middle - 1);
	temp->right = sortArray(arr, middle + 1, lastIndex);
	return temp;
}
struct node * convert_array_to_bst(int *arr, int len){
	if (arr == NULL)return NULL;
	struct node* root = NULL;
	len--;
	root = sortArray(arr, 0, len);
	return root;
}

