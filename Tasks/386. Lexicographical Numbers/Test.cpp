#include "CppUnitTest.h"

#include"386. Lexicographical Numbers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My386LexicographicalNumbers
{
	TEST_CLASS(My386LexicographicalNumbers) {
public:

	TEST_METHOD(TestMethod1) {
		int n = 13;
		int res_size, ans[] = { 1,10,11,12,13,2,3,4,5,6,7,8,9 };
		int ans_size = (sizeof(ans) / sizeof(ans[0]));

		int* res = lexicalOrder(n, &res_size);

		Assert::AreEqual(ans_size, res_size);
		for (int i = 0; i < ans_size; i++) {
			Assert::AreEqual(ans[0], res[0]);
		}
		free(res);
	}

	TEST_METHOD(TestMethod2) {
		int n = 2;
		int res_size, ans[] = { 1,2 };
		int ans_size = (sizeof(ans) / sizeof(ans[0]));

		int* res = lexicalOrder(n, &res_size);
		int a = sizeof(int*);
		int b = sizeof(int);
		Assert::AreEqual(ans_size, res_size);
		for (int i = 0; i < ans_size; i++) {
			Assert::AreEqual(ans[0], res[0]);
		}
		free(res);
	}

	TEST_METHOD(TestMethod3) {
		int n = 34;
		int res_size, ans[] = { 1,10,11,12,13,14,15,16,17,18,19,2,20,21,22,23,24,25,26,27,28,29,3,30,31,32,33,34,4,5,6,7,8,9 };
		int ans_size = (sizeof(ans) / sizeof(ans[0]));

		int* res = lexicalOrder(n, &res_size);

		Assert::AreEqual(ans_size, res_size);
		for (int i = 0; i < ans_size; i++) {
			Assert::AreEqual(ans[0], res[0]);
		}
		free(res);
	}
	};
}
