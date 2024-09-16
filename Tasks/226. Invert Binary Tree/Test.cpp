#include "CppUnitTest.h"

#include"226. Invert Binary Tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My226InvertBinaryTree
{

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

	struct TreeNode* createBinaryTreeFromArr(char* arr[], int arrLen) {
		struct TreeNode* root = NULL;
		fillBinaryTree(&root, arr, arrLen, 0, 0);
		return root;
	}

	void wrapBinaryTreeToArr(struct TreeNode* root, char** arr, int arrLen, int depth, int offset) {
		int pos = (1 << depth) - 1 + offset;
		if (pos >= arrLen) {
			return;
		}

		if (root == NULL) {
			arr[pos] = "null";
		} else {
			_itoa_s(root->val, arr[pos], 4, 10);
			wrapBinaryTreeToArr(root->left, arr, arrLen, depth + 1, offset * 2);
			wrapBinaryTreeToArr(root->right, arr, arrLen, depth + 1, offset * 2 + 1);
		}
	}

	TEST_CLASS(My226InvertBinaryTree) {
	public:

		TEST_METHOD(TestMethod1) {
			char* arr[] = { "4","2","7","1","3","6","9" };
			int arrLen = sizeof(arr) / sizeof(char*);
			char* ans[] = { "4","7","2","9","6","3","1" };
			struct TreeNode* root = createBinaryTreeFromArr(arr, arrLen);
			if (root == NULL) {
				return;
			}
			struct TreeNode* get = invertTree(root);

			char** res = (char**)malloc(sizeof(char*) * arrLen);
			if (res == NULL) {
				return;
			}
			for (int i = 0; i < arrLen; i++) {
				res[i] = (char*)malloc(sizeof(char) * 5);
				if (res[i] == NULL) {
					return;
				}
			}
			wrapBinaryTreeToArr(get, res, arrLen, 0, 0);

			for (int i = 0; i < arrLen; i++) {
				Assert::IsTrue(strcmp(ans[i], res[i]) == 0);
			}
		}

		TEST_METHOD(TestMethod2) {
			char* arr[] = { "2","1","3 " };
			int arrLen = sizeof(arr) / sizeof(char*);
			char* ans[] = { "2","3","1" };
			struct TreeNode* root = createBinaryTreeFromArr(arr, arrLen);
			if (root == NULL) {
				return;
			}
			struct TreeNode* get = invertTree(root);

			char** res = (char**)malloc(sizeof(char*) * arrLen);
			if (res == NULL) {
				return;
			}
			for (int i = 0; i < arrLen; i++) {
				res[i] = (char*)malloc(sizeof(char) * 5);
				if (res[i] == NULL) {
					return;
				}
			}
			wrapBinaryTreeToArr(get, res, arrLen, 0, 0);

			for (int i = 0; i < arrLen; i++) {
				Assert::IsTrue(strcmp(ans[i], res[i]) == 0);
			}
		}
	};
}
