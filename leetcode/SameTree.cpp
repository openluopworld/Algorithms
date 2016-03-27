
/*
 * Problem: Same Tree
 * 
 * Given two binary trees, write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 *
 * 可以考虑另外的情况：左右孩子可以交换也算一致。
 * 可以交换孩子的情况，使用递归更加简单
 */
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if ( p != NULL && q != NULL) {
        return (p->val==q->val) 
            && (isSameTree(p->left, q->left))
            && (isSameTree(p->right, q->right));
    } else if ( p == NULL && q == NULL ) {
        return true;
    } else {
        return false;
    }
}