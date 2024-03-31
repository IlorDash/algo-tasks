#include "pch.h"
#include "2-Add-Two-Numbers.h"

#include "stdlib.h"

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* resNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* prevResNode = NULL;
	struct ListNode* resHead = resNode;
	int carry = 0;
	bool l1_over = false;
	bool l2_over = false;

	while (!(l1_over && l2_over)) {
		if (l1_over && (!l2_over)) {
			resNode->val = (l2->val + carry) % 10;
			carry = (l2->val + carry) / 10;
		} else if (l2_over && (!l1_over)) {
			resNode->val = (l1->val + carry) % 10;
			carry = (l1->val + carry) / 10;
		} else {
			resNode->val = (l1->val + l2->val + carry) % 10;
			carry = (l1->val + l2->val + carry) / 10;
		}

		l1_over = (l1->next == NULL);
		l2_over = (l2->next == NULL);

		if (!(l1_over && l2_over)) {
			prevResNode = resNode;
			resNode = (struct ListNode*)malloc(sizeof(struct ListNode));
			prevResNode->next = resNode;
		}

		l1 = (l1_over) ? l1 : l1->next;
		l2 = (l2_over) ? l2 : l2->next;
	}

	resNode->next = NULL;

	if (carry == 1) {
		prevResNode = resNode;
		resNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		prevResNode->next = resNode;
		resNode->val = 1;
		resNode->next = NULL;
	}

	return resHead;
}