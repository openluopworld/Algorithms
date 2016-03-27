
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

bool judge (struct TreeNode *leftNode, struct TreeNode *rightNode) {
	 if ( leftNode == NULL && rightNode == NULL ) {return true;}
	 if ( leftNode == NULL || rightNode == NULL ) {return false;}
	 return (leftNode->val==rightNode->val) 
		 && judge(leftNode->left, rightNode->right) 
		 && judge(leftNode->right, rightNode->left);
}

bool isSymmetric(struct TreeNode* root) {
	if ( root == NULL ) {
		return true;
	} else {
		return judge(root->left, root->right);
	}
}

int main () {

}