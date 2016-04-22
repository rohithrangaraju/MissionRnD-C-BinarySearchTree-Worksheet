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
int minn(int a, int b){
	if (a < b)return a;
	else return b;
}
int  minDepth(struct node* root){
	if (root == NULL){
		return 0;
	}
	if (root->right == NULL&&root->right == NULL)return 0;
	return minn(minDepth(root->left), minDepth(root->right)) + 1;
}
int findrootKeyDistance(struct node* root,int value){
	printf("s");
	if (root != NULL) {
		int distance = 0;
		if ((root->data == value))return distance + 1;
		distance = findrootKeyDistance(root->left, value);
		if (distance > 0)return distance + 1;
	   distance = findrootKeyDistance(root->right, value);
		if (distance > 0)return distance + 1;
		return 0;
	}
	

}
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)return -1;
	if (root == temp) {
		int distance = minDepth(root);
		return distance+1;
	}
	if (temp->data > root->data){
		int rightDistance = minDepth(temp);
		rightDistance++;
		int rootD=findrootKeyDistance(root->left,temp->data);
		rootD--;
		int mainD = minDepth(root);
		mainD++;
		rootD = rootD + mainD;
		if (rootD == rightDistance)return rightDistance;
		else if (rootD < rightDistance)return rootD;
		else if(rootD>rightDistance) return rightDistance;
	}
	if (temp->data < root->data){
		int leftDistance = minDepth(temp);
		leftDistance++; int rootD = findrootKeyDistance(root->right, temp->data); rootD--;
		int mainD = minDepth(root);
		mainD++;
		rootD = rootD + mainD;
		if (rootD == leftDistance)return leftDistance;
		else if (rootD < leftDistance)return rootD;
		else if (rootD>leftDistance) return leftDistance;

	}
}