#include "pch.h"
#include "206-ReverseLinked-List.h"

#include "stdlib.h"

#define RECURSIVE false

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

struct ListNode* iterativelyReverse(struct ListNode* prev) {
	struct ListNode* node = prev->next;
	struct ListNode* nextNode;
	prev->next = NULL;
	while (node->next != NULL) {
		nextNode = node->next;
		node->next = prev;
		prev = node;
		node = nextNode;
	}
	node->next = prev;
	return node;
}

struct ListNode* reverseList(struct ListNode* head) {

	if ((head == NULL) || (head->next == NULL)) {
		return head;
	}

	return RECURSIVE ? (recursiveReverse(head)) : iterativelyReverse(head);
}