/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int treeSize(struct node* root){
	if (root == NULL)return 0;
	else return 1 + treeSize(root->left) + treeSize(root->right);
}

//void traversal
void getLevel(struct node* root, int level, int* a, int* index){
	if (root == NULL)return;
	if (level == 1){
		a[(*index)] = root->data;
		(*index)++;
	}
	if (level > 1){
		getLevel(root->right, level - 1, a, index);
		getLevel(root->left, level - 1, a, index);
	}
}
int height12(struct node *root1, int traverseLevel, int* Mainlevel){
	if (root1 == NULL){
		return 0;
	}


	if (traverseLevel > (*Mainlevel))
		(*Mainlevel) = traverseLevel;

	height12(root1->left, traverseLevel + 1, Mainlevel);
	height12(root1->right, traverseLevel + 1, Mainlevel);
	return *Mainlevel;
}
int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)return NULL;
	int n = treeSize(root);
	
	int *arr = (int*)calloc(n, sizeof(int));
	if (n == 1){ arr[0] = root->data; return arr; }
	int *i = (int*)calloc(1, sizeof(int));
	int height = height12(root,1,i);
	int j = 1;
	*i = 0;
	while (j <= height){
		getLevel(root, j, arr, i);
		j++;
	}
	return arr;
 
}
