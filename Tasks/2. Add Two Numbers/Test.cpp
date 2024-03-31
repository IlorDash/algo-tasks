#include "pch.h"
#include "CppUnitTest.h"

#include "2-Add-Two-Numbers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My2AddTwoNumbers
{
	TEST_CLASS(My2AddTwoNumbers) {
public:

	TEST_METHOD(TestMethod1) {
		//Input: l1 = [2,4,3], l2 = [5,6,4]
		//Output: [7,0,8]
		//Explanation: 342 + 465 = 807.

		struct ListNode l1[3];

		l1[0].val = 2;
		l1[0].next = &l1[1];
		l1[1].val = 4;
		l1[1].next = &l1[2];
		l1[2].val = 3;
		l1[2].next = NULL;

		struct ListNode l2[3];

		l2[0].val = 5;
		l2[0].next = &l2[1];
		l2[1].val = 6;
		l2[1].next = &l2[2];
		l2[2].val = 4;
		l2[2].next = NULL;

		const int ans_len = 3;

		struct ListNode ans[ans_len];

		ans[0].val = 7;
		ans[0].next = &ans[1];
		ans[1].val = 0;
		ans[1].next = &ans[2];
		ans[2].val = 8;
		ans[2].next = NULL;

		struct ListNode* res = addTwoNumbers(&l1[0], &l2[0]);

		for (size_t i = 0; i < ans_len; i++) {
			Assert::AreEqual(res->val, ans[i].val);
			res = res->next;
		}
		Assert::IsNull(res);
	}

	TEST_METHOD(TestMethod2) {
		//Input: l1 = [0], l2 = [0]
		//Output: [0]

		struct ListNode l1[1];

		l1[0].val = 0;
		l1[0].next = NULL;

		struct ListNode l2[1];

		l2[0].val = 0;
		l2[0].next = NULL;

		const int ans_len = 1;

		struct ListNode ans[ans_len];

		ans[0].val = 0;
		ans[0].next = NULL;

		struct ListNode* res = addTwoNumbers(&l1[0], &l2[0]);

		for (size_t i = 0; i < ans_len; i++) {
			Assert::AreEqual(res->val, ans[i].val);
			res = res->next;
		}
		Assert::IsNull(res);
	}

	TEST_METHOD(TestMethod3) {
		//Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
		//Output: [8,9,9,9,0,0,0,1]

		struct ListNode l1[7];

		l1[0].val = 9;
		l1[0].next = &l1[1];
		l1[1].val = 9;
		l1[1].next = &l1[2];
		l1[2].val = 9;
		l1[2].next = &l1[3];
		l1[3].val = 9;
		l1[3].next = &l1[4];
		l1[4].val = 9;
		l1[4].next = &l1[5];
		l1[5].val = 9;
		l1[5].next = &l1[6];
		l1[6].val = 9;
		l1[6].next = NULL;

		struct ListNode l2[4];

		l2[0].val = 9;
		l2[0].next = &l2[1];
		l2[1].val = 9;
		l2[1].next = &l2[2];
		l2[2].val = 9;
		l2[2].next = &l2[3];
		l2[3].val = 9;
		l2[3].next = NULL;

		const int ans_len = 8;

		struct ListNode ans[ans_len];

		ans[0].val = 8;
		ans[0].next = &ans[1];
		ans[1].val = 9;
		ans[1].next = &ans[2];
		ans[2].val = 9;
		ans[2].next = &ans[3];
		ans[3].val = 9;
		ans[3].next = &ans[4];
		ans[4].val = 0;
		ans[4].next = &ans[5];
		ans[5].val = 0;
		ans[5].next = &ans[6];
		ans[6].val = 0;
		ans[6].next = &ans[7];
		ans[7].val = 1;
		ans[7].next = NULL;

		struct ListNode* res = addTwoNumbers(&l1[0], &l2[0]);

		for (size_t i = 0; i < ans_len; i++) {
			Assert::AreEqual(res->val, ans[i].val);
			res = res->next;
		}
		Assert::IsNull(res);
	}
	};
}
