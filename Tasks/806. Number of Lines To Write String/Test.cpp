#include "pch.h"
#include "CppUnitTest.h"

#include "806. Number of Lines To Write String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My806NumberofLinesToWriteString
{
	TEST_CLASS(My806NumberofLinesToWriteString)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

		// Input: widths = [10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10], s = "abcdefghijklmnopqrstuvwxyz"
		// Output : [3, 60]
		// Explanation : You can write s as follows :
		// abcdefghij  // 100 pixels wide
		// klmnopqrst  // 100 pixels wide
		// uvwxyz      // 60 pixels wide
		// There are a total of 3 lines, and the last line is 60 pixels wide.

			int widths[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
			char* s = "abcdefghijklmnopqrstuvwxyz";
			int ans[] = { 3, 60 };

			int returnSize;
			int* res = numberOfLines(widths, sizeof(widths) / sizeof(int), s, &returnSize);

			Assert::AreEqual(ans[0], res[0]);
			Assert::AreEqual(ans[1], res[1]);

			free(res);
		}

		TEST_METHOD(TestMethod2) {

		// Input: widths = [4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10], s = "bbbcccdddaaa"
		// Output : [2, 4]
		// Explanation : You can write s as follows :
		// bbbcccdddaa  // 98 pixels wide
		// a            // 4 pixels wide
		// There are a total of 2 lines, and the last line is 4 pixels wide.

			int widths[] = { 4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
			char* s = "bbbcccdddaaa";
			int ans[] = { 2, 4 };

			int returnSize;
			int* res = numberOfLines(widths, sizeof(widths) / sizeof(int), s, &returnSize);

			Assert::AreEqual(ans[0], res[0]);
			Assert::AreEqual(ans[1], res[1]);

			free(res);
		}
	};
}
