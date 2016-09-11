/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        put(root);
    }  

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.size();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode * top = s.top();
        s.pop();
        put(top->right);
        return top->val;
    }
private:
    stack<TreeNode *> s;
    
    void put (TreeNode *node) {
        while ( node ) {
            s.push(node);
            node = node->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
