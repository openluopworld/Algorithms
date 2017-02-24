/*
 * Implement the following operations of a queue using stacks.
 * 
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 * Notes:
 * You must use only standard operations of a stack -- 
 * which means only push to top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively.
 * You may simulate a stack by using a list or deque (double-ended queue),
 * as long as you use only standard operations of a stack.
 * You may assume that all operations are valid (for example,
 * no pop or peek operations will be called on an empty queue).
*/

/**
 * LeetCode: Implement Queue using Stacks 
 * 
 * @author LuoPeng
 * @time 2015.8.3
 *
 */

class MyQueue {
    // Push element x to the back of queue.
    public void push(int x) {
        main.push(x);
    }

    // Removes the element from in front of queue.
    public void pop() {
        int size = main.size();
        for ( int i = 0; i < size-1; i++ ) {
            help.push(main.peek());
            main.pop();
        }
        main.pop();
        for ( int i = 0; i < size-1; i++) {
            main.push(help.peek());
            help.pop();
        }
    }

    // Get the front element.
    public int peek() {
        int size = main.size();
        for ( int i = 0; i < size-1; i++ ) {
            help.push(main.peek());
            main.pop();
        }
        int value = main.peek();
        for ( int i = 0; i < size-1; i++) {
            main.push(help.peek());
            help.pop();
        }
        return value;
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return main.empty();
    }
    
    private MyStack main = new MyStack();
    private MyStack help = new MyStack();
}

class MyStack {
    public void push(int x) {
        values.add(x);
    }
    public void pop() {
        values.remove(values.size()-1);
    }
    public int peek() {
        return values.get(values.size()-1);
    }
    public boolean empty() {
        return values.size() == 0;
    }
    public int size() {
        return values.size();
    }
    
    private List<Integer> values = new ArrayList<Integer>();
}