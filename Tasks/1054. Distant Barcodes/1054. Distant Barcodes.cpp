#include "1054. Distant Barcodes.h"

#include "stdlib.h"

int* cnt;

int sortBcCmp(const void* a, const void* b) {
	bool res = (cnt[*(int*)a] > cnt[*(int*)b]) || ((cnt[*(int*)a] == cnt[*(int*)b]) && (*(int*)a < *(int*)b));

	return (res) ? -1 : 1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize) {
	int* ret = (int*)malloc(barcodesSize * sizeof(int));
	*returnSize = barcodesSize;

	int maxBc = 0;
	for (int i = 0; i < barcodesSize; i++) {
		maxBc = (barcodes[i] > maxBc) ? barcodes[i] : maxBc;
	}
	maxBc++;
	cnt = (int*)malloc(maxBc * sizeof(int));
	for (int i = 0; i < maxBc; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < barcodesSize; i++) {
		cnt[barcodes[i]]++;
	}

	qsort(barcodes, barcodesSize, sizeof(int), sortBcCmp);

	for (int i = 0, k = 0; i < 2; i++) {
		for (int j = i; j < barcodesSize; j += 2) {
			ret[j] = barcodes[k++];
		}
	}
	return ret;
}