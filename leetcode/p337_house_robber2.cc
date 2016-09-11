/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        
        if ( !root ) { return 0; }
        
        int first = root->val;
        if ( root->left ) { first += rob(root->left->left) + rob(root->left->right); }
        if ( root->right ) { first += rob(root->right->left) + rob(root->right->right); }
        
        int second = rob(root->left) + rob(root->right);
        
        return (first>second)?first:second;
        
    }
};


// the solution is not good
