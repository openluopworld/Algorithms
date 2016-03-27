

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

/*
 * Problem : Reverse Linked List
 * 
 * Reverse a singly linked list.
 */
struct ListNode* reverseList(struct ListNode* head) {
	// int* i = NULL, *j = NULL;
	// j = (int*)malloc(8*sizeof(int));e
    if ( head == NULL || head->next == NULL) {
        return head;
    } else {
        struct ListNode *current = NULL, *beforeCurrent = NULL, *afterCurrent = NULL;
		beforeCurrent = head;
		current = beforeCurrent->next;
		while ( current != NULL) {
			afterCurrent = current->next;
			// reverse
			if (beforeCurrent->next == current) {
				beforeCurrent->next = NULL;
			}
			current->next = beforeCurrent;
			beforeCurrent = current;
			current = afterCurrent;
		}
		return beforeCurrent;
    }
}