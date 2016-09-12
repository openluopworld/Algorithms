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
    void flatten(TreeNode* root) {
        if (!root) { return; }
        // left is not null, right is not null
        if ( root->left && root->right) {
            flatten(root->right);
            flatten(root->left);
            lastNode(root->left)->right = root->right;
            root->right = root->left;
            root->left = NULL;
        } 
        // left is not null, right is null
        else if ( root->left ) {
            flatten(root->left);
            root->right = root->left;
            root->left = NULL;
        } 
        // left is null, right is not null
        else if ( root->right) {
            flatten(root->right);
        }
        
        // left is null, right is null, nothing to be done
    }
private:
    TreeNode * lastNode ( TreeNode *root) {
        while ( root->right) { // root can not be NULL
            root = root->right;
        }
        return root;
    }
};
