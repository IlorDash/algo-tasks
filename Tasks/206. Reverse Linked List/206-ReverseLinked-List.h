#pragma once

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head);
