/*
This Project will seem to be little tougher than before ones .But It can be done very easily
once you completed C-Recursion Project completely .

Note : You can use the functions specified as wrapper functions ,and write new functions 
which might take more parameters .

*/


#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void swap_nodes1(struct node *a, struct node *b){
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

struct node * new_node_spec1(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * add_node_spec1(struct node *root, int data){
	if (root == NULL) return new_node_spec1(data);

	if (data < root->data)
		root->left = add_node_spec1(root->left, data);
	else if (data > root->data)
		root->right = add_node_spec1(root->right, data);

	return root;
}
int findSize1(struct node *temp){
	int count = 1;
	if (temp == NULL) return 0;
	else{
		count += findSize1(temp->left);
		count += findSize1(temp->right);
	}
	return count;
}
void captureTreedata1(struct node* root, int *arr, int* index){
	if (root == NULL)return;
	captureTreedata1(root->left, arr, index);
	arr[(*index)] = root->data;
	(*index)++;
	captureTreedata1(root->right, arr, index);
}
void quicksort1(int *x, int first, int last)
{
	int pivot, j, temp, i;

	if (first<last){
		pivot = first;
		i = first;
		j = last;
		while (i<j)
		{
			while (x[i] <= x[pivot] && i<last)
				i++;
			while (x[j]>x[pivot])
				j--;
			if (i<j)
			{
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
		temp = x[pivot];
		x[pivot] = x[j];
		x[j] = temp;
		quicksort1(x, first, j - 1);
		quicksort1(x, j + 1, last);
	}
}
void setTreedata1(struct node* root, int *arr, int* index){
	if (root == NULL)return;
	setTreedata1(root->left, arr, index);
	root->data = arr[(*index)];
	(*index)++;
	setTreedata1(root->right, arr, index);
}
void fix_bst1(struct node *root){
	if (root == NULL)return;
	int n = findSize1(root);
	int *arrNode = (int*)calloc(n, sizeof(int));
	int *Index = (int*)calloc(1, sizeof(int));
	captureTreedata1(root, arrNode, Index);
	for (int i = 0; i < *Index; i++){
		printf("%d\t", arrNode[i]);
	}
	quicksort1(arrNode, 0, n - 1);
	printf("\n");
	for (int i = 0; i < *Index; i++){
		printf("%d\t", arrNode[i]);
	}
	*Index = 0;
	setTreedata1(root, arrNode, Index);
}


// Utility that prints out an array on a line. 


int main(){

	//Use it for testing ,Creating BST etc
	struct node *root = NULL;
	int nums[20] = { 50, 25, 75, 15, 35, 90, 5, 17, 45, 120, 1, 2, 19, 39, 49, 100 };

	for (int i = 0; i < 16; i++){
		root = add_node_spec1(root, nums[i]);
	}
	struct node *swaplist[2];
	int originaldata[2];
	swaplist[0] = root->left->right->right->left;
	swaplist[1] = root->right->right->right->left;
	originaldata[0] = swaplist[0]->data;
	originaldata[1] = swaplist[1]->data;

	swap_nodes1(swaplist[0], swaplist[1]);

	fix_bst1(root);
	getchar();
	return 0;
}
