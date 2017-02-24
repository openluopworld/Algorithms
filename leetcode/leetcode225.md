# LeetCode Problem 225, [Implement Stack using Queues]
2016.08.14

问题描述：使用队列实现栈的基本操作。假设不存在错误操作，比如空栈的pop(),top()操作等。

栈和队列是两种非常常见的数据结构。其中栈是LIFO(Last In First Out)，而队列是FIFO(First In First Out)。因此要想通过队列来实现栈，其中必然有一次方向的转化。

#### 1.1 Java实现
下面是leetcode上给出的一种[解法](https://discuss.leetcode.com/topic/47148/java-solution-2-queues)，用Java实现。

作者：leetcode@autumnJ

```Java
class MyStack {
    // Push element x onto stack.
    Queue<Integer> q1 = new LinkedList<Integer>();
    Queue<Integer> q2 = new LinkedList<Integer>();
    
    public void push(int x) {
       q1.add(x);
       while(!q2.isEmpty()){
           q1.add(q2.poll());
       }
       while(!q1.isEmpty()){
           q2.add(q1.poll());
       }
    }

    // Removes the element on top of the stack.
    public void pop() {
        q2.poll();
    }

    // Get the top element.
    public int top() {
        return q2.peek();
    }

    // Return whether the stack is empty.
    public boolean empty() {
       return q2.isEmpty(); 
    }
    
}
```

其实现逆序的关键在于第n个元素入队列A时，前n-1个元素保持在另外一个队列B中，在通过两次转移(B->A, A->B)将所有元素逆序保持在队列B中。

下图分别给出了加入1，2个元素后的情景，假设两次加入的元素的值分别为x，y。其中：

* front和trail分别表示队列的首,尾指针；
* q1和q2对应两个队列；
* 图中的a) b) c)三个子图分别对应push函数中三条语句执行后的情况；

<img alt="Adding the first element" src="http://1.lpxq.sinaapp.com/images/201608/16-08-14-stack1.png">

<img alt="Adding two elements" src="http://1.lpxq.sinaapp.com/images/201608/16-08-14-stack2.png">

#### 1.2 改进
上述实现中pop(),top()以及empty()的时间复杂度都是O(1)；push()的时间复杂度是O(n)，但每次新加入一个元素，都会出现2*n-1(其中n表示新元素加入后总的个数)次数据转移。由于两个队列都可以作为最终保存逆序的容器，第二个while循环可以省去，这样所有的函数在操作之前都需要先判断当前元素保存在那个栈中。

```Java
class MyStack {
    // Push element x onto stack.
    Queue<Integer> q1 = new LinkedList<Integer>();
    Queue<Integer> q2 = new LinkedList<Integer>();
    
    public void push(int x) {
       if ( q1.isEmpty() ) {
           q1.add(x);
           while(!q2.isEmpty()){
               q1.add(q2.poll());
           }
       } else {
           q2.add(x);
           while(!q1.isEmpty()){
               q2.add(q1.poll());
           }
       }
    }

    // Removes the element on top of the stack.
    public void pop() {
	if ( q1.isEmpty() ) {
            q2.poll();
        } else {
            q1.poll();
        }
    }

    // Get the top element.
    public int top() {
	if ( q1.isEmpty() ) {
            return q2.peek();
        } else {
            return q1.peek();
        }
    }

    // Return whether the stack is empty.
    public boolean empty() {
       return q1.isEmpty() && q2.isEmpty(); 
    }
    
}
```

[Implement Stack using Queues]: <https://leetcode.com/problems/implement-stack-using-queues/>
