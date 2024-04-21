#include "pch.h"
#include "CppUnitTest.h"

#include "2744. Find Maximum Number of String Pairs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My2744FindMaximumNumberofStringPairs
{
	TEST_CLASS(My2744FindMaximumNumberofStringPairs)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		// Input: words = ["cd", "ac", "dc", "ca", "zz"]
		// Output : 2
		// Explanation : In this example, we can form 2 pair of strings in the following way :
		// -We pair the 0th string with the 2nd string, as the reversed string of word[0] is "dc" and is equal to words[2].
		// - We pair the 1st string with the 3rd string, as the reversed string of word[1] is "ca" and is equal to words[3].
		// It can be proven that 2 is the maximum number of pairs that can be formed.

			char* words[] = { "cd", "ac", "dc", "ca", "zz" };
			int wordsSize = 5;
			int ans = 2;
			
			int res = maximumNumberOfStringPairs(words, wordsSize);

			Assert::AreEqual(ans, res);
		}

		TEST_METHOD(TestMethod2) {
		// Input: words = ["ab", "ba", "cc"]
		// Output : 1
		// Explanation : In this example, we can form 1 pair of strings in the following way :
		// -We pair the 0th string with the 1st string, as the reversed string of words[1] is "ab" and is equal to words[0].
		// It can be proven that 1 is the maximum number of pairs that can be formed.

			char* words[] = { "ab", "ba", "cc" };
			int wordsSize = 3;
			int ans = 1;

			int res = maximumNumberOfStringPairs(words, wordsSize);

			Assert::AreEqual(ans, res);
		}

		TEST_METHOD(TestMethod3) {
		// Input: words = ["aa", "ab"]
		// Output : 0
		// Explanation : In this example, we are unable to form any pair of strings.

			char* words[] = { "aa", "ab" };
			int wordsSize = 2;
			int ans = 0;

			int res = maximumNumberOfStringPairs(words, wordsSize);

			Assert::AreEqual(ans, res);
		}
	};
}
