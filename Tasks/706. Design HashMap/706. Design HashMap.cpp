#include "706. Design HashMap.h"

#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>

int hash(int key) {
	int hash = 0;
	while (key > 0) {
		hash += key % 10;
		key /= 10;
	}
	return hash;
}

int getIndex(int key) {
	return hash(key);
}

struct linkedList* createNode(int key, int val) {
	struct linkedList* node = (struct linkedList*)malloc(sizeof(struct linkedList));
	if (node == NULL) {
		return NULL;
	}
	node->next = NULL;
	node->key = key;
	node->val = val;

	return node;
}

struct linkedList* removeNode(struct linkedList* head, int key) {
	struct linkedList* tmp, *n = head;
	if (head->key == key) {
		tmp = head;
		head = head->next;
		free(tmp);
		return head;
	}
	while (n->next != NULL) {
		if (n->next->key == key) {
			tmp = n->next;
			n->next = n->next->next;
			free(tmp);
			break;
		}
		n = n->next;
	}
	return head;
}

struct linkedList* putNode(struct linkedList* head, int key, int val) {
	if (head->key == key) {
		head->val = val;
		return head;
	}

	struct linkedList* n = head;
	while (n->next != NULL) {
		if (n->key == key) {
			n->val = val;
			return head;
		}
		n = n->next;
	}

	if (n->key == key) {
		n->val = val;
		return head;
	}
	n->next = createNode(key, val);
	return head;
}

struct linkedList* getNode(struct linkedList* head, int key) {
	struct linkedList* n = head;
	while (n != NULL) {
		if (n->key == key) {
			break;
		}
		n = n->next;
	}
	return n;
}

MyHashMap* myHashMapCreate() {
	MyHashMap* obj = (MyHashMap*)malloc(sizeof(MyHashMap));
	if (obj == NULL) {
		return NULL;
	}
	obj->arr = (struct linkedList**)malloc(sizeof(struct linkedList*));
	obj->arrLen = 0;

	return obj;
}

void myHashMapIncreaseIndex(MyHashMap* obj, int newKeyIndex) {
	struct linkedList** newArr = (struct linkedList**)malloc(sizeof(struct linkedList*) * (newKeyIndex + 1));
	struct linkedList** tmp;
	if (newArr == NULL) {
		return;
	}
	memcpy(newArr, obj->arr, obj->arrLen * sizeof(struct linkedList*));
	for (int i = obj->arrLen; i <= newKeyIndex; i++) {
		newArr[i] = NULL;
	}
	tmp = obj->arr;
	obj->arr = newArr;
	free(tmp);
	obj->arrLen = newKeyIndex + 1;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
	int newKeyIndex = getIndex(key);
	if (newKeyIndex >= obj->arrLen) {
		myHashMapIncreaseIndex(obj, newKeyIndex);
	}

	if (obj->arr[newKeyIndex] == NULL) {
		obj->arr[newKeyIndex] = createNode(key, value);
	} else {
		obj->arr[newKeyIndex] = putNode(obj->arr[newKeyIndex], key, value);
	}

}

int myHashMapGet(MyHashMap* obj, int key) {
	int keyIndex = getIndex(key);
	if (keyIndex >= obj->arrLen) {
		return -1;
	}
	if (obj->arr[keyIndex] == NULL) {
		return -1;
	}
	struct linkedList* node = getNode(obj->arr[keyIndex], key);
	if (node == NULL) {
		return -1;
	}
	return node->val;
}

void myHashMapRemove(MyHashMap* obj, int key) {
	int keyIndex = getIndex(key);
	if (keyIndex >= obj->arrLen) {
		return;
	}
	if (obj->arr[keyIndex] == NULL) {
		return;
	}
	obj->arr[keyIndex] = removeNode(obj->arr[keyIndex], key);
}

void myHashMapFree(MyHashMap* obj) {
	for (int i = 0; i < obj->arrLen; i++) {
		struct linkedList* tmp;
		while (obj->arr[i] != NULL) {
			tmp = obj->arr[i];
			obj->arr[i] = obj->arr[i]->next;
			free(tmp);
		}
		
	}
	free(obj->arr);
	free(obj);
}