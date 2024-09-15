#include "110. Balanced Binary Tree.h"

#include <stdlib.h>
#include <string.h>

void fillBinaryTree(struct TreeNode** node, char* arr[], int arrLen, int depth, int offset) {
	int nodePos = (1 << depth) - 1 + offset;

	if ((nodePos < arrLen) && (strcmp(arr[nodePos], "null")) != 0) {
		*node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		if (*node == NULL) {
			return;
		}
		(*node)->val = atoi(arr[nodePos]);
		fillBinaryTree(&(*node)->left, arr, arrLen, depth + 1, offset * 2);
		fillBinaryTree(&(*node)->right, arr, arrLen, depth + 1, offset * 2 + 1);
	} else {
		*node = NULL;
	}

}

struct TreeNode* createBinaryTree(char* arr[], int arrLen) {
	struct TreeNode* root = NULL;
	fillBinaryTree(&root, arr, arrLen, 0, 0);
	return root;
}

int isBalancedRecursion(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	short leftDepth, rightDepth;

	leftDepth = isBalancedRecursion(root->left);
	if (leftDepth == -1) {
		return leftDepth;
	}

	rightDepth = isBalancedRecursion(root->right);
	if (rightDepth == -1) {
		return rightDepth;
	}

	if ((leftDepth > rightDepth) && ((leftDepth - rightDepth) > 1)) {
		return -1;
	} else if ((rightDepth > leftDepth) && ((rightDepth - leftDepth) > 1)) {
		return -1;
	}

	if (leftDepth > rightDepth) {
		return leftDepth + 1;
	} else {
		return rightDepth + 1;
	}
}

bool isBalanced(struct TreeNode* root) {
	if (root == NULL) {
		return true;
	}
	return (isBalancedRecursion(root) != -1);
}