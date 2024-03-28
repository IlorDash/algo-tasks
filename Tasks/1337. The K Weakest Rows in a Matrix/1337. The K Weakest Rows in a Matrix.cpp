#include "1337. The K Weakest Rows in a Matrix.h"

#include <stdlib.h>

struct DoubleListNode {
	int num;
	int* col;
	struct DoubleListNode* prev;
	struct DoubleListNode* next;
};

struct DoubleListNode* createMatRowsDList(int** mat, int matSize, int* matColSize) {
	struct DoubleListNode* matRowsList = (struct DoubleListNode*)malloc(matSize * sizeof(struct DoubleListNode));
	matRowsList[0].num = 0;
	matRowsList[0].col = (int*)malloc(*matColSize * sizeof(int));
	matRowsList[0].col = mat[0];
	matRowsList[0].prev = NULL;
	matRowsList[0].next = &matRowsList[1];
	for (int i = 1; i < (matSize - 1); i++) {
		matRowsList[i].num = i;
		matRowsList[i].col = (int*)malloc(*matColSize * sizeof(int));
		matRowsList[i].col = mat[i];
		matRowsList[i].prev = &matRowsList[i - 1];
		matRowsList[i].next = &matRowsList[i + 1];
	}
	matRowsList[matSize - 1].num = matSize - 1;
	matRowsList[matSize - 1].col = (int*)malloc(*matColSize * sizeof(int));
	matRowsList[matSize - 1].col = mat[matSize - 1];
	matRowsList[matSize - 1].prev = &matRowsList[matSize - 2];
	matRowsList[matSize - 1].next = NULL;

	return matRowsList;
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {

	struct DoubleListNode* matRowsList = createMatRowsDList(mat, matSize, matColSize);

	int* res = (int*)malloc(k * sizeof(int));
	int resCntr = 0;
	*returnSize = k;
	struct DoubleListNode* rowHead = &(matRowsList[0]);
	struct DoubleListNode* row;
	bool goingToNextCol = true;

	for (int i = 0; i < k; i++) {
		res[i] = 0;
	}

	for (int i = 0; i < *matColSize; i += (goingToNextCol ? 1 : 0)) {
		row = rowHead;
		goingToNextCol = true;
		while (row != NULL) {
			if (row->col[i] == 0) {
				bool isRowFirst = (row->num == rowHead->num);
				bool isRowLast = (row->next == NULL);
				if (isRowFirst) {
					rowHead = rowHead->next;
				} else if (isRowLast) {
					row->prev->next = row->next;
				} else {
					row->prev->next = row->next;
					row->next->prev = row->prev;
				}
				goingToNextCol = false;
				res[resCntr] = row->num;
				resCntr++;
				break;
			}
			row = row->next;
		}

		if (resCntr == k) {
			break;
		}
	}
	row = rowHead;
	while (resCntr != k) {
		res[resCntr] = row->num;
		row = row->next;
		resCntr++;
	}
	return res;
}