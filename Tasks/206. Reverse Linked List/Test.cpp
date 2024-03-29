#include "pch.h"
#include "CppUnitTest.h"

#include "206-ReverseLinked-List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My206ReverseLinkedList
{
	TEST_CLASS(My206ReverseLinkedList)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			//Input: head = [1,2,3,4,5]
			//Output: [5,4,3,2,1]

			const int len = 5;
			struct ListNode list[len];

			list[0].val = 1;
			list[0].next = &list[1];
			list[1].val = 2;
			list[1].next = &list[2];
			list[2].val = 3;
			list[2].next = &list[3];
			list[3].val = 4;
			list[3].next = &list[4];
			list[4].val = 5;
			list[4].next = NULL;

			struct ListNode ans[len];

			ans[0].val = 5;
			ans[0].next = &ans[1];
			ans[1].val = 4;
			ans[1].next = &ans[2];
			ans[2].val = 3;
			ans[2].next = &ans[3];
			ans[3].val = 2;
			ans[3].next = &ans[4];
			ans[4].val = 1;
			ans[4].next = NULL;

			struct ListNode* res = reverseList(&list[0]); 

			for (size_t i = 0; i < len; i++) {
				Assert::AreEqual(res->val, ans[i].val);
				res = res->next;
			}
			Assert::IsNull(res);
		}

		TEST_METHOD(TestMethod2) {
			//Input: head = [1,2]
			//Output: [2,1]

			const int len = 2;
			struct ListNode list[len];

			list[0].val = 1;
			list[0].next = &list[1];
			list[1].val = 2;
			list[1].next = NULL;

			struct ListNode ans[len];

			ans[0].val = 2;
			ans[0].next = &ans[1];
			ans[1].val = 1;
			ans[1].next = NULL;

			struct ListNode* res = reverseList(&list[0]);

			for (size_t i = 0; i < len; i++) {
				Assert::AreEqual(res->val, ans[i].val);
				res = res->next;
			}
			Assert::IsNull(res);
		}

		TEST_METHOD(TestMethod3) {
			//Input: head = []
			//Output: []

			const int len = 0;
			struct ListNode * list = NULL;

			struct ListNode* ans = NULL;

			struct ListNode* res = reverseList(list);

			Assert::IsNull(res);
		}

		TEST_METHOD(TestMethod4) {
			//Input: head = [1]
			//Output: [1]

			const int len = 1;
			struct ListNode list[len];

			list[0].val = 1;
			list[0].next = NULL;

			struct ListNode ans[len];

			ans[0].val = 1;
			ans[0].next = NULL;

			struct ListNode* res = reverseList(list);

			Assert::AreEqual(ans[0].val, res->val);
			Assert::IsNull(res->next);
		}
	};
}
