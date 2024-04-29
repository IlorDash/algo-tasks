#include "CppUnitTest.h"

#include"1781. Sum of Beauty of All Substrings.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My1781SumofBeautyofAllSubstrings
{
	TEST_CLASS(My1781SumofBeautyofAllSubstrings) {
public:

	TEST_METHOD(TestMethod1) {
		//	Example 1:

		//Input: s = "aabcb"
		//	Output : 5
		//	Explanation : The substrings with non - zero beauty are["aab", "aabc", "aabcb", "abcb", "bcb"], each with beauty equal to 1.

		char s[] = "aabcb";
		int ans = 5;

		int res = beautySum(s);

		Assert::AreEqual(ans, res);
	}

	TEST_METHOD(TestMethod2) {
		//	Example 2:

		//Input: s = "aabcbaa"
		//	Output : 17

		char s[] = "aabcbaa";
		int ans = 17;

		int res = beautySum(s);

		Assert::AreEqual(ans, res);
	}

	TEST_METHOD(TestMethod3) {
		//	Example 3:

		//Input: s = "abaacc"
		//	Output : 12

		char s[] = "abaacc";
		int ans = 12;

		int res = beautySum(s);

		Assert::AreEqual(ans, res);
	}
	};
}
