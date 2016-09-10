
/*
 * Problem: Binary Tree Right Side View
 * 
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 */


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
    /*
     * broad search first, and only access the right most node of each level
     */
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result;
        TreeNode * temp = root;
        queue<TreeNode*> cur, next;
    
        if ( root ) {
            cur.push(root);
            while( !cur.empty() ) {
                // access the right most element
                temp = cur.front();
                result.push_back(temp->val);
                while ( !cur.empty() ) {
                    temp = cur.front();
                    cur.pop();
                    if ( temp->right ) { next.push(temp->right); }
                    if ( temp->left) { next.push(temp->left); }
                }
                cur.swap(next);
            }
        }
        
        return result;
    }
};
