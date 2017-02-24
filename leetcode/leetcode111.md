# LeetCode Problem 111, Minimun Depth of Binary Tree
2016.08.13

* 题目描述：给定一课二叉树，求二叉树的最短深度，即最短路径的长度。

```C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
	if ( NULL == root ) {
		return 0;
	} else if ( NULL == root->left ) {
		return minDepth(root->right)+1;
	} else if ( NULL == root->right ) {
		return minDepth(root->left)+1;
	} else {
		int leftDepth = minDepth(root->left);
		int rightDepth = minDepth(root->right);
		return (leftDepth < rightDepth)?leftDepth+1:rightDepth+1;
	}
}
```

* 注意下面的这种**错误解法**

```C
int minDepth(struct TreeNode* root) {
	if ( NULL == root ) { return 0; }
	int leftDepth = minDepth(root->left);
	int rightDepth = minDepth(root->right);
	return (leftDepth < rightDepth)?leftDepth+1:rightDepth+1;
}
```

* **在最短路径中，一颗子树如果为空，它的长度为０，一定是最小的；但实际上是不存在这条最短路径的。在求最长路径的长度是可以这样，是因为最长路径一定是一条可达的路径**。

```C
int maxDepth(struct TreeNode* root) {
	if ( NULL == root ) { return 0; }
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	return (leftDepth > rightDepth)?leftDepth+1:rightDepth+1;
}
```
