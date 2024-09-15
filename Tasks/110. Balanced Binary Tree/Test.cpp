#include "CppUnitTest.h"

#include "110. Balanced Binary Tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My110BalancedBinaryTree
{
	TEST_CLASS(My110BalancedBinaryTree) {
public:

	TEST_METHOD(TestMethod1) {
		char* arr[] = { "3", "9", "20", "null", "null", "15", "7" };
		bool ans = true;
		struct TreeNode* root = createBinaryTree(arr, 7);
		if (root == NULL) {
			return;
		}
		bool get = isBalanced(root);
		Assert::AreEqual(ans, get);
	}

	TEST_METHOD(TestMethod2) {
		char* arr[] = { "1","2","2","3","3","null","null","4","4"};
		bool ans = false;
		struct TreeNode* root = createBinaryTree(arr, 9);
		if (root == NULL) {
			return;
		}
		bool get = isBalanced(root);
		Assert::AreEqual(ans, get);
	}
	};
}
