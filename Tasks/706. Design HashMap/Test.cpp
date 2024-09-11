#include "CppUnitTest.h"

#include "706. Design HashMap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My706DesignHashMap
{
	TEST_CLASS(My706DesignHashMap) {
public:

	TEST_METHOD(TestMethod1) {
		MyHashMap* obj = myHashMapCreate();
		myHashMapPut(obj, 123, 10);
		myHashMapFree(obj);
	}

	TEST_METHOD(TestMethod2) {
		int key = 123, val = 10;
		int ans = 10;

		MyHashMap* obj = myHashMapCreate();
		myHashMapPut(obj, key, val);
		int get = myHashMapGet(obj, key);

		Assert::AreEqual(ans, get);

		myHashMapFree(obj);
	}

	TEST_METHOD(TestMethod3) {
		int key = 123, val = 10;
		int ans = -1;

		MyHashMap* obj = myHashMapCreate();
		myHashMapPut(obj, key, val);
		myHashMapRemove(obj, key);
		int get = myHashMapGet(obj, key);

		Assert::AreEqual(ans, get);

		myHashMapFree(obj);
	}

	TEST_METHOD(TestMethod4) {
		int key1 = 123, val1 = 10;
		int key2 = 321, val2 = 20;
		int ans = 20;

		MyHashMap* obj = myHashMapCreate();
		myHashMapPut(obj, key1, val1);
		myHashMapPut(obj, key2, val2);
		int get = myHashMapGet(obj, key2);

		Assert::AreEqual(ans, val2);

		myHashMapFree(obj);
	}

	TEST_METHOD(TestMethod5) {
		int key1 = 123, val1 = 10;
		int key2 = 321, val2 = 20;
		int ans = 20;

		MyHashMap* obj = myHashMapCreate();

		myHashMapPut(obj, key1, val1);
		myHashMapPut(obj, key2, val2);

		myHashMapRemove(obj, key1);

		int get = myHashMapGet(obj, key2);
		Assert::AreEqual(ans, val2);

		myHashMapRemove(obj, 2);

		myHashMapFree(obj);
	}

	TEST_METHOD(TestMethod6) {
		int key1 = 1, val1 = 1;
		int key2 = 2, val2 = 2;
		int key3 = 2, val3 = 1;
		int ans1 = 1;
		int ans2 = -1;
		int ans3 = 1;
		int ans4 = -1;

		MyHashMap* obj = myHashMapCreate();

		myHashMapPut(obj, key1, val1);
		myHashMapPut(obj, key2, val2);

		int get = myHashMapGet(obj, 1);
		Assert::AreEqual(ans1, get);
		get = myHashMapGet(obj, 3);
		Assert::AreEqual(ans2, get);

		myHashMapPut(obj, key3, val3);

		get = myHashMapGet(obj, 2);
		Assert::AreEqual(ans3, get);

		myHashMapRemove(obj, 2);

		get = myHashMapGet(obj, 2);
		Assert::AreEqual(ans4, get);

		myHashMapFree(obj);
	}
	TEST_METHOD(TestMethod7) {
		int key[] = { 0, 11, 12, 1, 7, 1, 2 };
		int val[] = { 3, 1, 1, 19, 3, 8, 6 };
		int ans1 = -1;
		int ans2 = 1;

		MyHashMap* obj = myHashMapCreate();
		myHashMapRemove(obj, 14);

		int get = myHashMapGet(obj, 4);
		Assert::AreEqual(ans1, get);

		myHashMapPut(obj, key[0], val[0]);
		myHashMapPut(obj, key[1], val[1]);
		myHashMapPut(obj, key[2], val[2]);

		get = myHashMapGet(obj, 11);
		Assert::AreEqual(ans2, get);

		myHashMapPut(obj, key[3], val[3]);
		myHashMapPut(obj, key[4], val[4]);
		myHashMapPut(obj, key[5], val[5]);
		myHashMapPut(obj, key[6], val[6]);

		myHashMapFree(obj);
	}

	TEST_METHOD(TestMethod8) {
		int key1 = 7, key2 = 16, val1 = 1, val2 = 2;

		MyHashMap* obj = myHashMapCreate();

		myHashMapPut(obj, key1, val1);
		myHashMapPut(obj, key2, val2);

		myHashMapRemove(obj, 16);

		myHashMapFree(obj);
	}
	};
}
