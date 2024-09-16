#include "226. Invert Binary Tree.h"

#include "stdlib.h"

struct TreeNode* invertTreeRecursion(struct TreeNode* root) {
	if (root == NULL) {
		return NULL;
	}
	invertTreeRecursion(root->left);
	invertTreeRecursion(root->right);
	struct TreeNode* tmpLeft = root->left;
	root->left = root->right;
	root->right = tmpLeft;
	return root;
}

struct TreeNode* invertTree(struct TreeNode* root) {
	return invertTreeRecursion(root);
}