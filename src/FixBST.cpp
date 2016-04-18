/*
Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .
*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
		int data;
	struct node *right;
};
int findSize(struct node *temp){
	int count = 1;
	if (temp == NULL) return 0;
	else{
		count += findSize(temp->left);
		count += findSize(temp->right);
	}
	return count;
}
void captureTreedata(struct node* root,int *arr,int* index){
	if (root == NULL)return;
	captureTreedata(root->left, arr, index);
	arr[(*index)] = root->data;
	(*index)++;
	captureTreedata(root->right, arr, index);
}
void quicksort(int *x, int first, int last)
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
		quicksort(x, first, j - 1);
		quicksort(x, j + 1, last);
	}
}
void setTreedata(struct node* root, int *arr, int* index){
	if (root == NULL)return;
	setTreedata(root->left, arr, index);
	root->data = arr[(*index)];
	(*index)++;
	setTreedata(root->right, arr, index);
}
void fix_bst(struct node *root){
	if (root == NULL)return;
	int n = findSize(root);
	int *arrNode = (int*)calloc(n, sizeof(int));
	int *Index = (int*)calloc(1, sizeof(int));
	captureTreedata(root, arrNode, Index);
	quicksort(arrNode, 0, n-1);
	*Index = 0;
	setTreedata(root, arrNode, Index);
}