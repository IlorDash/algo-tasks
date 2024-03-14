#include "412. Fizz Buzz.h"
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>

#define FIZZ_BUZZ_LEN 9

char** fizzBuzz(int n, int* returnSize) {
	char** answer = (char**)malloc(n * sizeof(char*));

	*returnSize = n;

	for (int i = 0; i < n; i++) {
		answer[i] = (char*)malloc(FIZZ_BUZZ_LEN * sizeof(char));
		bool isFizz = ((i + 1) % 3 == 0);
		bool isBuzz = ((i + 1) % 5 == 0);

		if (isFizz && isBuzz) {
			strcpy(answer[i], "FizzBuzz");
		} else if (isFizz) {
			strcpy(answer[i], "Fizz");
		} else if (isBuzz) {
			strcpy(answer[i], "Buzz");
		} else {
			sprintf(answer[i], "%d", (i + 1));
		}
	}
	return answer;
}