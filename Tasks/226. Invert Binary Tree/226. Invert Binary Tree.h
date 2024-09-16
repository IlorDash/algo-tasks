#pragma once

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;

};

struct TreeNode* invertTree(struct TreeNode* root);