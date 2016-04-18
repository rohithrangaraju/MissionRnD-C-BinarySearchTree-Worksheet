/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};

void depthTraversal(struct node* root, int level, int *index,int *arr){
	if (root == NULL)return;
	if (root->left == NULL&&root->right == NULL)arr[(*index)++] = level;
	depthTraversal(root->left, level+1, index, arr);
	depthTraversal(root->right, level+1, index, arr);
}
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	//if (root == NULL || temp == NULL)return -1;
	int *p = (int*)calloc(1, sizeof(int));
	int a[50];
	depthTraversal(temp,0 , p,a);
	int min = a[0];
	for (int i = 1; i < *p; i++){
		if (min>a[i])min = a[i];
	}
	return min;
}