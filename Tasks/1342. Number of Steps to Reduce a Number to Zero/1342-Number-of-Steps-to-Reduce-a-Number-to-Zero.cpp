#include "1342-Number-of-Steps-to-Reduce-a-Number-to-Zero.h"

int numberOfSteps(int num) {
	int steps = 0;
	while (num != 0) {
		num = (num % 2 == 0) ? num >> 1 : num - 1;
		steps++;
	}
	return steps;
}