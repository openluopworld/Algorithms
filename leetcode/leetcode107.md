# LeetCode Problem 107, Binary Tree Level Order Traversal II
2016.08.13

### **[Solution 1]**
作者：leetcode@liopi

```C
int maxTreeHeight (struct TreeNode *ptr) {
    int p, q;
    if (ptr == NULL) return 0;
    p = maxTreeHeight (ptr->left);
    q = maxTreeHeight (ptr->right);
    return p > q ? p + 1 : q + 1;
}

void cunt (struct TreeNode* ptr, int target, int current, int *size_ptr) {
    if (!ptr) return;
    if (target == current) {
        (*size_ptr)++;
        return;
    }
    cunt (ptr->left, target, current + 1, size_ptr);
    cunt (ptr->right, target, current + 1, size_ptr);
}

void fill (struct TreeNode* ptr, int target, int current, int *index, int *lv_ptr) {
    if (!ptr) return;
    if (target == current) {
        lv_ptr[*index] = ptr->val;
        ++*index;
        return;
    }
    fill (ptr->left, target, current + 1, index, lv_ptr);
    fill (ptr->right, target, current + 1, index, lv_ptr);
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int i, j, **arr_ptr, size, index;
    if (root == NULL) return NULL;
    *returnSize = maxTreeHeight(root);
    arr_ptr = (int **)malloc(*returnSize * sizeof(int *));
    *columnSizes = (int *)malloc(*returnSize * sizeof(int));
    for (i = *returnSize;i > 0; i--) {
        j = 1;
        size = 0;
        index = 0;
        cunt (root, i, j, &size);
        (*columnSizes)[*returnSize - i] = size;
        arr_ptr[*returnSize - i] = (int *)malloc(size * sizeof(int));
        fill (root, i, j, &index, arr_ptr[*returnSize - i]);
    }
    return arr_ptr;
}
```


### **[Solution 2]**
作者：leetcode@fuiiii

```Java
public class Solution {
    public ArrayList<ArrayList<Integer>> levelOrderBottom(TreeNode root) {
        //1.bfs and add them to a stack, 
        //but bfs from right to left, 
        //and add mark when finish a level
        //2.pop stack out and add to list
        
        if(root==null) return new ArrayList<ArrayList<Integer>>();
        //1:
        Queue<TreeNode> q=new LinkedList<TreeNode>();
        Stack<Integer>  s=new Stack<Integer>();
        q.add(root);
        TreeNode curr;
        s.push(-99);//push first marker
        int sc=0;//stack count:number of nodes in stack of this level level
        int nc=1;//node count: number of nodes in this level
        int nlnc=0;//next level node count:number of nodes in next level
        while(!q.isEmpty()){
            curr=q.poll();
            if(curr.right!=null) {q.add(curr.right); nlnc++;} 
            if(curr.left!=null)  {q.add(curr.left); nlnc++;}
            s.push(curr.val);
            sc++;
            if(sc==nc){//reach the end of the level
                s.push(-99);//marker
                sc=0;
                nc=nlnc;
                nlnc=0;
            }
        }
        s.pop();//pop the last marker
        //2.
        ArrayList<ArrayList<Integer>> res=new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> currL=new ArrayList<Integer>();
        int c;
        while(!s.isEmpty()){
            c=s.pop();
            if(c!=-99){
                currL.add(c);
            }else{
                res.add(currL);
                currL=new ArrayList<Integer>();
            }
        }
        return res;
        
    }
}
```

[Solution 1]:<https://discuss.leetcode.com/topic/40907/c-accepted-solution>
[Solution 2]:<https://discuss.leetcode.com/topic/765/wrong-answer-error/2>
