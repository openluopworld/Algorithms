/**
 * LeetCode: Palindrome Linked List
 * Given a singly linked list, determine if it is a palindrome.
 * Could you do it in O(n) time and O(1) space?
 * 
 * @author LuoPeng
 * @time 2015.8.3
 *
 */
public class Solution {
    
    /**
     * Reverse the second part, then compare the nodes one by one.
     * Time: O(n) + O((n-1)/2) + O(n/2-1) + O(n/2) + O(1) = O(n)
     * Space: Only 7 parameters are needed, so it is O(1)
     * 
     * @param head the first node of a linked list
     * @return true if it is a palindrome, false otherwise.
     */
    public boolean isPalindrome(ListNode head) {
        
        if ( head == null || head.next == null) {return true;}
        
        ListNode middle = null; // the middle index of linked list
        ListNode current = null; // the nodes need to be reversed
        ListNode lastHaveReversed = null; // the last node that has been reversed 
        ListNode temp = head; 
        
        /*
         * the size of linked list
         * Time: O(n)
         */
        int length = 0;
        while (temp != null) {
            temp = temp.next;
            length++;
        }
        
        /*
         * get the index of middle
         * Time: O((n-1)/2)
         */
        int i = 0, size;
        middle = head;
        size = (length-1)/2;
        while ( i < size) {
            middle = middle.next;
            i++;
        }
        
        /*
         * reverse the last half part, from middleNext to the end
         * just like the insert-sort
         * Time: O(n/2-1)
         */
        size = length/2-1; // the number of nodes need to be reversed
        lastHaveReversed = middle.next;
        current = lastHaveReversed.next;
        for ( i = 0; i < size; i++) {
            lastHaveReversed.next = current.next;
            current.next = middle.next;
            middle.next = current;
            current = lastHaveReversed.next;
        }
        
        /*
         * judge
         * Time: O(n/2)
         */
        temp = head; // the start of first part
        middle = middle.next; // the start of second part
        for ( i = 0; i < length/2; i++) {
            if ( temp.val == middle.val) {
                temp = temp.next;
                middle = middle.next;
            } else {
                break;
            }
        }
         
        return i == length/2;
        
    }
    
    /**
     * For every node in the first part, find the other one in the second part and compare the value
     * Time: O(n)
     * Space: O(1)
     * 
     * @param head
     * @return
     */
    public boolean isPalindrome2(ListNode head) {
        if ( head == null || head.next == null) {
            return true;
        } else {
            ListNode temp = head; 
            int length = 0;
            while (temp != null) {
                temp = temp.next;
                length++;
            }
            
            int i, j;
            for ( i = 0; i < length/2; i++) {
                j = i;
                temp = head;
                while (j < length-1-i) {
                    temp = temp.next;
                    j++;
                }
                if ( head.val != temp.val) {
                    break;
                }
                head = head.next;
            }
            return i == length/2;
        }
    }
    
}