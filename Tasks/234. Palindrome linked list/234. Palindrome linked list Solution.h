#pragma once

#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

bool isPalindrome(struct ListNode *head);
