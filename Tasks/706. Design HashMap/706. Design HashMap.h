#pragma once

struct linkedList {
	int key;
	int val;
	struct linkedList* next;
};

typedef struct {
	struct linkedList** arr;
	int arrLen;
} MyHashMap;


MyHashMap* myHashMapCreate();

void myHashMapPut(MyHashMap* obj, int key, int value);
int myHashMapGet(MyHashMap* obj, int key);
void myHashMapRemove(MyHashMap* obj, int key);
void myHashMapFree(MyHashMap* obj);