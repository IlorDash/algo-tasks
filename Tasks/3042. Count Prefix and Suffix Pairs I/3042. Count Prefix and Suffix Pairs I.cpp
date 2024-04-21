#include "pch.h"

#include "3042. Count Prefix and Suffix Pairs I.h"

#include <string.h>

bool is_prefix(char* scan, char* seq, int scan_len, int seq_len) {

	if (scan_len < seq_len) {
		return false;
	}

	for (int i = 0; i < seq_len; i++) {
		if (scan[i] != seq[i]) {
			return false;
		}
	}
	return true;
}

bool is_suffix(char* scan, char* seq, int scan_len, int seq_len) {
	if (scan_len < seq_len) {
		return false;
	}
	int j = scan_len - 1;
	for (int i = (seq_len - 1); i >= 0; i--) {
		if (scan[j] != seq[i]) {
			return false;
		}
		j--;
	}
	return true;
}

bool isPrefixAndSuffix(char* str1, char* str2) {
	int str_len1 = strlen(str1);
	int str_len2 = strlen(str2);

	return is_prefix(str2, str1, str_len2, str_len1) && is_suffix(str2, str1, str_len2, str_len1);
}

int countPrefixSuffixPairs(char** words, int wordsSize) {
	int pairsNum = 0;

	for(int i = 0; i < wordsSize; i++) {
		for (int j = i + 1; j < wordsSize; j++) {
			if (isPrefixAndSuffix(words[i], words[j])) {
				pairsNum++;
			}
		}
	}
	return pairsNum;
}