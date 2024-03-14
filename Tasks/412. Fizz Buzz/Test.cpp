#include "CppUnitTest.h"

#include"412. Fizz Buzz.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My412FizzBuzz
{
	TEST_CLASS(My412FizzBuzz) {
public:

	TEST_METHOD(TestMethod1) {
		int returnSize, n = 3;
		char* ans[] = { "1", "2", "Fizz" };

		char** res = fizzBuzz(n, &returnSize);

		for (int i = 0; i < n; i++) {
			Assert::IsTrue(strcmp(ans[i], res[i]) == 0);
		}

		for (int i = 0; i < n; i++) {
			free(res[i]);
		}
		free(res);
	}
	TEST_METHOD(TestMethod2) {
		int returnSize, n = 5;
		char* ans[] = { "1","2","Fizz","4","Buzz" };

		char** res = fizzBuzz(n, &returnSize);

		for (int i = 0; i < n; i++) {
			Assert::IsTrue(strcmp(ans[i], res[i]) == 0);
		}

		for (int i = 0; i < n; i++) {
			free(res[i]);
		}
		free(res);
	}
	TEST_METHOD(TestMethod3) {
		int returnSize, n = 15;
		char* ans[] = { "1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz" };

		char** res = fizzBuzz(n, &returnSize);

		for (int i = 0; i < n; i++) {
			Assert::IsTrue(strcmp(ans[i], res[i]) == 0);
		}

		for (int i = 0; i < n; i++) {
			free(res[i]);
		}
		free(res);
	}
	};
}
