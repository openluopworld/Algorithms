/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        if ( !root ) return;
        
        queue<TreeLinkNode *> curQueue, nextQueue;
        TreeLinkNode *curNode = NULL;
        TreeLinkNode *nextNode = NULL;
        
        curQueue.push(root);
        while ( !curQueue.empty() ) {
            curNode = curQueue.front();
            curQueue.pop();
            if ( curNode->left ) { nextQueue.push(curNode->left); } // add left tree
            if ( curNode->right ) { nextQueue.push(curNode->right); } // add right tree
            while ( !curQueue.empty() ) { // has next node
                nextNode = curQueue.front();
                curQueue.pop();
                if ( nextNode->left ) { nextQueue.push(nextNode->left); } // add left tree
                if ( nextNode->right ) { nextQueue.push(nextNode->right); } // add right tree
                curNode->next = nextNode;
                curNode = nextNode;
            }
            curNode->next = NULL; // the last node of the current level
            curQueue.swap(nextQueue);
        }
    }
};
