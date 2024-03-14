#include "383. Ransom Note.h"

#include <string.h>

#define ALPHABET_LEN 26

struct letterNode {
	char l;
	int n;
};

void fillLetterList(char* str, int len, struct letterNode* list) {
	for (int i = 0; i < len; i++) {
		if (list[str[i] - 'a'].n == 0) {
			list[str[i] - 'a'].l = str[i];
			list[str[i] - 'a'].n = 1;
		} else if (str[i] == list[str[i] - 'a'].l) {
			list[str[i] - 'a'].n++;
		}
	}
}

bool canConstruct(char* ransomNote, char* magazine) {
	struct letterNode letterList[ALPHABET_LEN];

	memset(&letterList, 0, sizeof letterList);
	fillLetterList(magazine, strlen(magazine), letterList);

	int note_len = strlen(ransomNote);

	for (int i = 0; i < note_len; i++) {
		if (letterList[ransomNote[i] - 'a'].n == 0) {
			return false;
		}

		if (letterList[ransomNote[i] - 'a'].l == '\0') {
			return false;
		}

		letterList[ransomNote[i] - 'a'].n--;
	}
	return true;
}