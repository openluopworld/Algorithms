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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int temp;
        vector<int> inverse;
        if ( root ) { levelOrder(root, 1, res); }
        for ( int i = 0; i < res.size(); ++i ) {
            // the odd levels
            if ( i%2 ) {
                for ( int j = res[i].size()-1; j >= 0; --j ) {
                    inverse.push_back(res[i][j]);
                }
                res[i].clear(); // let inverse be empty for next
                res[i].swap(inverse);
            }
        }
        return res;
    }
private:
    void levelOrder(TreeNode *root, int level, vector<vector<int>> &res) {
        // the first time at this level
        if ( level > res.size()) {
            res.push_back(vector<int>());
        }
        
        res[level-1].push_back(root->val);
        if ( root->left) { levelOrder(root->left, level+1, res); }
        if ( root->right) { levelOrder(root->right, level+1, res); }
    }
};