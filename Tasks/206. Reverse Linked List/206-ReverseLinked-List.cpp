#include "pch.h"
#include "206-ReverseLinked-List.h"

#include "stdlib.h"

struct ListNode* recursiveReverse(struct ListNode* prev) {
	struct ListNode* node = prev->next;
	struct ListNode* newHead;

	if (node->next == NULL) {
		node->next = prev;
		prev->next = NULL;
		return node;
	}
	newHead = recursiveReverse(node);
	node->next = prev;
	prev->next = NULL;
	return newHead;
}

struct ListNode* reverseList(struct ListNode* head) {

	if ((head == NULL) || (head->next == NULL)) {
		return head;
	}

	return recursiveReverse(head);
}