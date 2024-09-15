#pragma once

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;

};

bool isBalanced(struct TreeNode* root);
struct TreeNode* createBinaryTree(char* arr[], int arrLen);