#include "pch.h"
#include "CppUnitTest.h"

#include "900. RLE Iterator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace My900RLEIterator
{
	TEST_CLASS(My900RLEIterator)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Input
			// ["RLEIterator", "next", "next", "next", "next"]
			// [[[3, 8, 0, 9, 2, 5]], [2], [1], [1], [2]]
			// Output
			// [null, 8, 8, 5, -1]
			vector <int> encoding = { 3, 8, 0, 9, 2, 5 };

			vector <int> res;
			vector <int> ans = { 8, 8, 5, -1 };

			RLEIterator* rLEIterator = new RLEIterator(encoding); // This maps to the sequence [8,8,8,5,5].

			/* exhausts 2 terms of the sequence, returning 8. The remaining sequence is now [8, 5, 5]. */
			res.push_back(rLEIterator->next(2));

			/* exhausts 1 term of the sequence, returning 8. The remaining sequence is now [5, 5]. */
			res.push_back(rLEIterator->next(1));

			/* exhausts 1 term of the sequence, returning 5. The remaining sequence is now [5]. */
			res.push_back(rLEIterator->next(1));

			/* exhausts 2 terms, returning -1. This is because the first term exhausted was 5, but the second term did not exist.Since the last term exhausted does not exist, we return -1. */
			res.push_back(rLEIterator->next(2));

			Assert::IsTrue(ans == res, L"Unexpected value for <subsets>");
		}
	};
}
