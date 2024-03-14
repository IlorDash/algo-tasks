#include "234. Palindrome linked list Solution.h"

bool isPalindrome(struct ListNode* head) {
	if (head == NULL) {
		return false;
	}

	struct ListNode* node = head;
	unsigned short node_len = 0;

	struct ListNode* ptr_arr[100000] = { 0 };

	while (node) {
		ptr_arr[node_len] = node;
		node_len++;
		node = node->next;
	}

	if (node_len == 1) {
		return true;
	}

	node = head;
	unsigned short node_iter = node_len - 1;
	while ((node->val == ptr_arr[node_iter]->val) && (node->next != ptr_arr[node_iter]) && (node != ptr_arr[node_iter])) {
		node = node->next;
		node_iter--;
	}
	if (node->val == ptr_arr[node_iter]->val) {
		return true;
	}
	return false;
}