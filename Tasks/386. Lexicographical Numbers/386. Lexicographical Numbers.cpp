#include "386. Lexicographical Numbers.h"

#include "stdlib.h"

void traverseNumsTrie(int n, int currNum, int* numbers, int* index) {
	numbers[(*index)++] = currNum;
	for (int i = 0; i <= 9; i++) {
		int newNum = currNum * 10 + i;
		if (newNum > n) {
			return;
		}
		traverseNumsTrie(n, newNum, numbers, index);
	}
}

int* lexicalOrder(int n, int* returnSize) {
	int* numbers = (int*)malloc(n * sizeof(int));
	int index = 0;

	for (int i = 1; i <= 9; i++) {
		if (i > n) {
			break;
		}
		traverseNumsTrie(n, i, numbers, &index);
	}

	*returnSize = n;
	return numbers;
}