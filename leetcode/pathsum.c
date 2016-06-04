
/**
 * Problem 112 Path Sum
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
 * such that adding up all the values along the path equals the given sum.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
	if ( NULL == root ) { return false; }
	else if ( (NULL == root->left)
		&& (NULL == root->right)
		&& (sum== root->val) ) {
		return true;
	} 
	else { 
		return hasPathSum(root->left, sum-root->val)
			|| hasPathSum(root->right, sum-root->val);
	}
}
