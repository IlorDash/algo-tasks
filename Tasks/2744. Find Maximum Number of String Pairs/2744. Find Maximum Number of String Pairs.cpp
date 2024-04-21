#include "pch.h"

#include "2744. Find Maximum Number of String Pairs.h"

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>

bool check_pair(char* str1, char* str2) {
	int str_len = strlen(str1);
	for (int i = 0; i < str_len; i++) {
		if (str1[i] != str2[str_len - i - 1]) {
			return false;
		}
	}
	return true;
}

int maximumNumberOfStringPairs(char** words, int wordsSize) {
	int pairsNum = 0;
	int i = 0;

	while (i < wordsSize) {
		for (int j = i + 1; j < wordsSize; j++) {
			if (check_pair(words[i], words[j])) {
				pairsNum++;
				break;
			}
		}
		i++;
	}
	return pairsNum;
}