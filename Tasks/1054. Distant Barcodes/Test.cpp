#include "CppUnitTest.h"

#include "1054. Distant Barcodes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My1054DistantBarcodes
{
	TEST_CLASS(My1054DistantBarcodes) {
public:

	TEST_METHOD(TestMethod1) {
		// Input: barcodes = [1, 1, 1, 2, 2, 2]
		// Output : [1, 2, 1, 2, 1, 2]

		int barcodes[] = { 1, 1, 1, 2, 2, 2 };
		int ans[] = { 1, 2, 1, 2, 1, 2 };
		int arr_size = sizeof(barcodes) / sizeof(int);

		int returnSize;
		int* res = rearrangeBarcodes(barcodes, arr_size, &returnSize);

		for (int i = 1; i < arr_size; i++) {
			bool notEqual = (res[i] != res[i - 1]);
			Assert::IsTrue(notEqual);
			Assert::AreEqual(ans[i], res[i]);
		}

		free(res);
	}
	TEST_METHOD(TestMethod2) {
		// Input: barcodes = [1, 1, 1, 1, 2, 2, 3, 3]
		// Output : [1, 2, 1, 2, 1, 3, 1, 3]
		int barcodes[] = { 1, 1, 1, 1, 2, 2, 3, 3 };
		int ans[] = { 1, 2, 1, 2, 1, 3, 1, 3 };
		int arr_size = sizeof(barcodes) / sizeof(int);

		int returnSize;
		int* res = rearrangeBarcodes(barcodes, arr_size, &returnSize);

		for (int i = 0; i < arr_size; i++) {
			Assert::AreEqual(ans[i], res[i]);
		}
		free(res);
	}
	TEST_METHOD(TestMethod3) {
		// Input: barcodes = [1, 1, 1, 2, 2, 2, 3]
		// Output : [1, 2, 1, 2, 1, 3, 2]

		int barcodes[] = { 1, 1, 1, 2, 2, 2, 3 };
		int ans[] = { 1, 2, 1, 2, 1, 3, 2 };
		int arr_size = sizeof(barcodes) / sizeof(int);

		int returnSize;
		int* res = rearrangeBarcodes(barcodes, arr_size, &returnSize);

		for (int i = 0; i < arr_size; i++) {
			Assert::AreEqual(ans[i], res[i]);
		}

		free(res);
	}
	TEST_METHOD(TestMethod4) {
		// Input: barcodes = [1]
		// Output : [1]

		int barcodes[] = { 1 };
		int ans[] = { 1 };
		int arr_size = sizeof(barcodes) / sizeof(int);

		int returnSize;
		int* res = rearrangeBarcodes(barcodes, arr_size, &returnSize);

		for (int i = 0; i < arr_size; i++) {
			Assert::AreEqual(ans[i], res[i]);
		}

		free(res);
	}
	TEST_METHOD(TestMethod5) {
		// Input: barcodes = [2,2,5,5]
		// Output : [2,5,2,5]

		int barcodes[] = { 2,2,5,5 };
		int ans[] = { 2,5,2,5 };
		int arr_size = sizeof(barcodes) / sizeof(int);

		int returnSize;
		int* res = rearrangeBarcodes(barcodes, arr_size, &returnSize);

		for (int i = 0; i < arr_size; i++) {
			Assert::AreEqual(ans[i], res[i]);
		}

		free(res);
	}
	TEST_METHOD(TestMethod6) {
		// Input: barcodes = [7,7,7,8,5,7,5,5,5,8]
		// Output : [5,7,5,7,5,7,5,8,7,8]

		int barcodes[] = { 7,7,7,8,5,7,5,5,5,8 };
		int ans[] = { 5,7,5,7,5,7,5,8,7,8 };
		int arr_size = sizeof(barcodes) / sizeof(int);

		int returnSize;
		int* res = rearrangeBarcodes(barcodes, arr_size, &returnSize);

		for (int i = 0; i < arr_size; i++) {
			Assert::AreEqual(ans[i], res[i]);
		}

		free(res);
	}
	TEST_METHOD(TestMethod7) {
		// Input: barcodes = [2,2,2,1,5]
		// Output : [2,1,2,5,2]

		int barcodes[] = { 2,2,2,1,5 };
		int ans[] = { 2,1,2,5,2 };
		int arr_size = sizeof(barcodes) / sizeof(int);

		int returnSize;
		int* res = rearrangeBarcodes(barcodes, arr_size, &returnSize);

		for (int i = 0; i < arr_size; i++) {
			Assert::AreEqual(ans[i], res[i]);
		}

		free(res);
	}
	TEST_METHOD(TestMethod8) {
		// Input: barcodes = [2,2,2,1,1,1,5,5]
		// Output : [1,2,1,2,1,5,2,5]

		int barcodes[] = { 2, 2, 2, 1, 1, 1, 5, 5 };
		int ans[] = { 1, 2, 1, 2, 1, 5, 2, 5 };
		int arr_size = sizeof(barcodes) / sizeof(int);

		int returnSize;
		int* res = rearrangeBarcodes(barcodes, arr_size, &returnSize);

		for (int i = 0; i < arr_size; i++) {
			Assert::AreEqual(ans[i], res[i]);
		}

		free(res);
	}
	TEST_METHOD(TestMethod9) {
		// Input: barcodes = [2,2,1,3]
		// Output : [2,1,2,3]

		int barcodes[] = { 2,2,1,3 };
		int ans[] = { 2,1,2,3 };
		int arr_size = sizeof(barcodes) / sizeof(int);

		int returnSize;
		int* res = rearrangeBarcodes(barcodes, arr_size, &returnSize);

		for (int i = 0; i < arr_size; i++) {
			Assert::AreEqual(ans[i], res[i]);
		}

		free(res);
	}
	};
}
