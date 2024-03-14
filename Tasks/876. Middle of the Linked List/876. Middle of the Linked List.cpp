#include "876. Middle of the Linked List.h"

#include <stdio.h>

struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* mean = head;
	int headCntr = 1;
	int meanCntr = 1;
	
	while (head->next != NULL) {
		head = head->next;
		headCntr++;
		if((headCntr / 2 + (1 - headCntr % 2)) != meanCntr){
			mean = mean->next;
			meanCntr = headCntr / 2 + headCntr % 2;
		}
	}
	return mean;
}