#include "1781. Sum of Beauty of All Substrings.h"

#include "string.h"
#include "limits.h"

#define ENG_ALPHABET_LEN 26

int calcBeauty(int* map) {
	int maxCharNum = 0;
	int minCharNum = INT_MAX;
	for (int i = 0; i < ENG_ALPHABET_LEN; i++) {
		maxCharNum = (map[i] > maxCharNum) ? map[i] : maxCharNum;
		minCharNum = ((minCharNum > map[i]) && (map[i] != 0)) ? map[i] : minCharNum;
	}
	return maxCharNum - minCharNum;
}

int beautySumRecursion(char* s, int len, int* map) {
	int res = 0;
	if (len == 3) {
		for (int i = 0; i < len; i++) {
			map[(int)s[i] - (int)'a']++;
		}
	} else {
		res = beautySumRecursion(s, len - 1, map);
		map[(int)s[len - 1] - (int)'a']++;
	}
	
	return (res + calcBeauty(map));
}

int beautySum(char* s) {
	int s_len = strlen(s);
	int map[ENG_ALPHABET_LEN] = { 0 };
	int res = 0;

	for (int i = 0; i <= (s_len - 3); i++) {
		res += beautySumRecursion(s + i, s_len - i, map);
		memset(map, 0, sizeof(map));
	}
	return res;
}