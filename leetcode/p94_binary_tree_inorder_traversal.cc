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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode * temp = NULL; 
        if ( !root ) return res;
        
        pushLeftNodes(root);
        while (!s.empty()) {
            temp = s.top();
            s.pop();
            res.push_back(temp->val);
            pushLeftNodes(temp->right);
        }
        
        
        return res;
    }
private:
    stack<TreeNode*> s;
    void pushLeftNodes(TreeNode *root) {
        while( root ) {
            s.push(root);
            root = root->left;
        }
    }
};
