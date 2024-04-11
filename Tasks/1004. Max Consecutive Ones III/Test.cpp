#include "pch.h"
#include "CppUnitTest.h"

#include"1004. Max Consecutive Ones III.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My1004MaxConsecutiveOnesIII
{
	TEST_CLASS(My1004MaxConsecutiveOnesIII) {
public:

	TEST_METHOD(TestMethod1) {
		// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
		// Output : 6
		// Explanation : [1,1,1,0,0,1,1,1,1,1,1]

		int numsSize = 11;
		int nums[11] = { 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 };
		int k = 2;
		int ans = 6;

		int res = longestOnes(nums, numsSize, k);

		Assert::AreEqual(ans, res);
	}

	TEST_METHOD(TestMethod2) {
		// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
		// Output : 10
		// Explanation : [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]

		int numsSize = 19;
		int nums[19] = { 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1 };
		int k = 3;
		int ans = 10;

		int res = longestOnes(nums, numsSize, k);

		Assert::AreEqual(ans, res);
	}

	TEST_METHOD(TestMethod3) {
		// Input: nums = [0,0,0,1], k = 4
		// Output : 4

		int numsSize = 4;
		int nums[4] = { 0, 0, 0, 1 };
		int k = 4;
		int ans = 4;

		int res = longestOnes(nums, numsSize, k);

		Assert::AreEqual(ans, res);
	}

	TEST_METHOD(TestMethod4) {
		// Input: nums = [1], k = 4
		// Output : 1

		int numsSize = 1;
		int nums[4] = { 1 };
		int k = 4;
		int ans = 1;

		int res = longestOnes(nums, numsSize, k);

		Assert::AreEqual(ans, res);
	}

	TEST_METHOD(TestMethod5) {
		// Input: nums = [0,0,1,1,1,0,0], k = 0
		// Output : 3

		int numsSize = 7;
		int nums[7] = { 0,0,1,1,1,0,0 };
		int k = 0;
		int ans = 3;

		int res = longestOnes(nums, numsSize, k);

		Assert::AreEqual(ans, res);
	}

	TEST_METHOD(TestMethod6) {
		// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 0
		// Output : 4

		int numsSize = 19;
		int nums[19] = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };
		int k = 0;
		int ans = 4;

		int res = longestOnes(nums, numsSize, k);

		Assert::AreEqual(ans, res);
	}
	};
}
