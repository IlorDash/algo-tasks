#include "pch.h"
#include "CppUnitTest.h"

#include "3042. Count Prefix and Suffix Pairs I.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My3042CountPrefixandSuffixPairsI
{
	TEST_CLASS(My3042CountPrefixandSuffixPairsI)
	{
	public:
		
		TEST_METHOD(TestMethod1) {
		// Input: words = ["a", "aba", "ababa", "aa"]
		// Output : 4
		// Explanation : In this example, the counted index pairs are :
		// i = 0 and j = 1 because isPrefixAndSuffix("a", "aba") is true.
		// i = 0 and j = 2 because isPrefixAndSuffix("a", "ababa") is true.
		// i = 0 and j = 3 because isPrefixAndSuffix("a", "aa") is true.
		// i = 1 and j = 2 because isPrefixAndSuffix("aba", "ababa") is true.
		// Therefore, the answer is 4.

			char* words[] = { "a", "aba", "ababa", "aa" };
			int wordsSize = 4;
			int ans = 4;

			int res = countPrefixSuffixPairs(words, wordsSize);

			Assert::AreEqual(ans, res);
		}

		TEST_METHOD(TestMethod2) {
		// Input: words = ["pa", "papa", "ma", "mama"]
		// Output : 2
		// Explanation : In this example, the counted index pairs are :
		// i = 0 and j = 1 because isPrefixAndSuffix("pa", "papa") is true.
		// i = 2 and j = 3 because isPrefixAndSuffix("ma", "mama") is true.
		// Therefore, the answer is 2.

			char* words[] = { "pa", "papa", "ma", "mama" };
			int wordsSize = 4;
			int ans = 2;

			int res = countPrefixSuffixPairs(words, wordsSize);

			Assert::AreEqual(ans, res);
		}

		TEST_METHOD(TestMethod3) {
		// Input: words = ["abab", "ab"]
		// Output : 0
		// Explanation : In this example, the only valid index pair is i = 0 and j = 1, and isPrefixAndSuffix("abab", "ab") is false.
		// Therefore, the answer is 0.

			char* words[] = { "abab", "ab" };
			int wordsSize = 2;
			int ans = 0;

			int res = countPrefixSuffixPairs(words, wordsSize);

			Assert::AreEqual(ans, res);
		}
	};
}
