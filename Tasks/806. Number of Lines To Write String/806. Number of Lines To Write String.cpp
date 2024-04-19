#include "pch.h"

#include "806. Number of Lines To Write String.h"

#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char* s, int* returnSize) {
	int len = 100;

	int* res = (int*)malloc(sizeof(int) * 2);
	res[0] = 0;
	res[1] = 0;

	for (int i = 0; i < strlen(s); i++) {
		if (len >= widths[(int)s[i] - (int)'a']) {
			len -= widths[(int)s[i] - (int)'a'];
			res[1] += widths[(int)s[i] - (int)'a'];
		} else {
			res[0] += 1;
			res[1] = widths[(int)s[i] - (int)'a'];
			len = 100 - widths[(int)s[i] - (int)'a'];
		}
	}

	res[0] += (res[1] > 0) ? 1 : 0;
	*returnSize = 2;

	return res;
}