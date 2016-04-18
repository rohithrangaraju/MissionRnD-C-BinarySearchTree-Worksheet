/*
1)Given a BST ,Find its Maximum Height

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input :

10
/\
5 80
/  /
2  50
\
4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs
*/
#include <stdlib.h>
#include <stdio.h>
//#include<malloc.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int height(struct node *root1, int traverseLevel, int* Mainlevel){
	if (root1 == NULL)
		return *(Mainlevel);

	if (traverseLevel > *Mainlevel)
		*Mainlevel = traverseLevel;

	height(root1->left, traverseLevel++, Mainlevel);
	height(root1->right, traverseLevel++, Mainlevel);
}
int get_height(struct node *root){
	if (root == NULL)return -1;
	int *mainLevel = (int*)calloc(1, sizeof(int));
	int n = height(root, 1, mainLevel);
	free(mainLevel);
	return n;
}
int leftSum(struct node* root, int *sum){
	if (root == NULL) return *sum;
	*sum += root->data;
	leftSum(root->left, sum);
	leftSum(root->right, sum);
}
int get_left_subtree_sum(struct node *root){
	if (root == NULL)return -1;
	int *addLeft = (int*)calloc(1, sizeof(int));
	int lsum = leftSum(root->left, addLeft);
	free(addLeft);
	return lsum;
}
int rightSum(struct node* root, int* sum)
{
	if (root == NULL) return *sum;
	*sum += root->data;
	rightSum(root->left, sum);
	rightSum(root->right, sum);
}
int get_right_subtree_sum(struct node *root){
	//	return 0;
	if (root == NULL)return -1;
	int *addRight = (int*)calloc(1, sizeof(int));
	int rsum = rightSum(root->right, addRight);
	free(addRight);
	return rsum;
}