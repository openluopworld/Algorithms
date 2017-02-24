import java.util.ArrayList;
import java.util.List;

/**
 * LeetCode: Lowest Common Ancestor of a Binary Search Tree 
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST
 * 
 * @author LuoPeng
 * @time 215.8.5
 *
 */
public class LowestCommonAncestor {

    /**
     * If a node A is the common ancestor, and its left child and right child are not at the same time.
     * A is the Lowest Common Ancestor
     * 
     * @param root the root of the tree
     * @param p 
     * @param q 
     * @return lowest common ancestor (LCA) of p and q
     */
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        
        if ( root == null || p == root || q == root) {return root;}
        
        TreeNode lca = null;
        /*
         * If one child is null, the lowest common ancestor must be the child of the other child of root
         */
        if ( root.left == null) {
            lca = lowestCommonAncestor(root.right, p, q);
        } else if ( root.right == null) {
            lca = lowestCommonAncestor(root.left, p, q);
        } else {
            boolean first = isCommonAncestor(root.left, p, q);
            boolean second = isCommonAncestor(root.right, p, q);
            if ( first) {
                // if root.left is a common ancestor, the LCA must be root.left or a child of it.
                lca = lowestCommonAncestor(root.left, p, q);
            } else if (second) {
                // if root.right is a common ancestor, the LCA must be root.right or a child of it.
                lca = lowestCommonAncestor(root.right, p, q);
            } else {
                // For root is a common ancestor of p and q, the LCA must be root if the left child
                // and right child are not the common ancestors.
                lca = root;
            }
        }
        
        return lca;
    }
    
    /**
     * Whether root is the common ancestor of p and q 
     * 
     * @param root a node
     * @param p a node
     * @param q a node
     * @return True if root is the common ancestor of p and q, otherwise false.
     */
    private boolean isCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if ( root == null) {return false;}
        
        TempQueue queue = new TempQueue();
        TreeNode temp = null;
        boolean first = false;
        boolean second = false;
        
        // Breadth First Search
        queue.push(root);
        while ( !queue.empty()) {
            temp = queue.peek();
            queue.pop();
            if ( temp ==p) {
                first = true;
            } else if ( temp == q) {
                second = true;
            }
            // add the child
            if ( temp.left != null) {
                queue.push(temp.left);
            }
            if ( temp.right != null) {
                queue.push(temp.right);
            }
            // break if p and q have bean found
            if ( first && second) {
                break;
            }
        }
        
        return first && second;
    }
    
}

/**
 * Queue
 *
 */
class TempQueue {
    public void push(TreeNode x) {
        values.add(x);
    }

    public void pop() {
        values.remove(0);
    }

    public TreeNode peek() {
        return values.get(0);
    }

    public int size() {
        return values.size();
    }
    
    public boolean empty() {
        return values.size()==0;
    }
    
    private List<TreeNode> values = new ArrayList<TreeNode>();
}