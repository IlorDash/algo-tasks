#include "CppUnitTest.h"

#include "1342-Number-of-Steps-to-Reduce-a-Number-to-Zero.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My1342NumberofStepstoReduceaNumbertoZero
{
	TEST_CLASS(My1342NumberofStepstoReduceaNumbertoZero)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int num = 123;
			int ans = 12;

			int out = numberOfSteps(num);
			Assert::AreEqual(ans, out);
		}
		TEST_METHOD(TestMethod2) {
			int num = 14;
			int ans = 6;

			int out = numberOfSteps(num);
			Assert::AreEqual(ans, out);
		}
		TEST_METHOD(TestMethod3) {
			int num = 1;
			int ans = 1;

			int out = numberOfSteps(num);
			Assert::AreEqual(ans, out);
		}
		TEST_METHOD(TestMethod4) {
			int num = 0;
			int ans = 0;

			int out = numberOfSteps(num);
			Assert::AreEqual(ans, out);
		}
	};
}
