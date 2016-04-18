/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output :   specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task :
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorder1(struct node *root, int *arr, int* i){
	if (root == NULL)return;
	inorder1(root->left, arr, i);
	arr[*i] = root->data;
	(*i)++;
	inorder1(root->right, arr, i);

}
void inorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL) return;
	int *s = (int*)calloc(1, sizeof(int));
	inorder1(root, arr, s);
	free(s);
}
void preorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL) return;
	*arr = root->data;
	//arr++;
	preorder(root->left, ++arr);
	preorder(root->right, ++arr);
}
void postorder1(struct node *root, int *arr, int* i){
	if (root == NULL || arr == NULL) //++arr;
		return;
	postorder1(root->left, arr, i);
	postorder1(root->right, arr, i);

	arr[*i] = root->data;
	(*i)++;
}
void postorder(struct node *root, int *arr){
	if (arr == NULL) return;
	int *s = (int*)calloc(1, sizeof(int));
	postorder1(root, arr, s);
	free(s);
}
