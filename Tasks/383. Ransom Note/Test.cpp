#include "CppUnitTest.h"

#include "383. Ransom Note.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define TESTS_NUM 3

namespace My383RansomNote
{
	TEST_CLASS(My383RansomNote) {
		char* ransomNote[TESTS_NUM] = {"a", "aa", "aa" };
		char* magazine[TESTS_NUM] = {"b", "ab", "aab" };
public:

	TEST_METHOD(TestMethod1) {
		Assert::AreEqual(false, canConstruct(ransomNote[0], magazine[0]));
	}
	TEST_METHOD(TestMethod2) {
		Assert::AreEqual(false, canConstruct(ransomNote[1], magazine[1]));
	}
	TEST_METHOD(TestMethod3) {
		Assert::AreEqual(true, canConstruct(ransomNote[2], magazine[2]));
	}
	};
}
