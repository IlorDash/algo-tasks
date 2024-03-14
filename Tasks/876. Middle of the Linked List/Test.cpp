#include "CppUnitTest.h"

#include"876. Middle of the Linked List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My876MiddleoftheLinkedList
{
	TEST_CLASS(My876MiddleoftheLinkedList) {
public:

	TEST_METHOD(TestMethod1) {
		//Input: head = [1,2,3,4,5]
		//Output: [3,4,5]
		//Explanation: The middle node of the list is node 3.

		struct ListNode list[5];

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

		Assert::AreEqual(list[2].val, middleNode(&list[0])->val);

	}
	TEST_METHOD(TestMethod2) {
		//Input: head = [1, 2, 3, 4, 5, 6]
		//	Output : [4, 5, 6]
		//	Explanation : Since the list has two middle nodes with values 3 and 4, we return the second one.

		struct ListNode list[6];

		list[0].val = 1;
		list[0].next = &list[1];
		list[1].val = 2;
		list[1].next = &list[2];
		list[2].val = 3;
		list[2].next = &list[3];
		list[3].val = 4;
		list[3].next = &list[4];
		list[4].val = 5;
		list[4].next = &list[5];
		list[5].val = 6;
		list[5].next = NULL;

		Assert::AreEqual(list[3].val, middleNode(&list[0])->val);

	}
	};
}
