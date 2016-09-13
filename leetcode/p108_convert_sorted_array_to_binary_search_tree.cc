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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = NULL;
        if ( nums.size() > 0 ) { conTree(root, nums, 0, nums.size()); }
        return root;
    }
private:
    void conTree(TreeNode* &root, vector<int> &nums, int start, int end) {
        if ( start < end ) {
            int index = (start+end)/2; // the root node index
            root = new TreeNode(nums[index]);
            if ( start < index ) { conTree(root->left, nums, start, index); }
            if ( index+1 < end ) { conTree(root->right, nums, index+1, end); }
        }
    }
};
