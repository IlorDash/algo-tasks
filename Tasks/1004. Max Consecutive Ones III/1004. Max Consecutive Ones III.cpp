#include "1004. Max Consecutive Ones III.h"

#include "pch.h"

int longestOnesSlidingWindow(int* nums, int numsSize, int k) {
	int maxOnesLen = 0, onesLen = 0;
	int leftIndex = 0, rightIndex = 0;
	int flips = 0;
	while (rightIndex < numsSize) {
		do {
			onesLen += nums[rightIndex];
			if ((nums[rightIndex] == 0) && (flips < k)) {
				flips++;
				onesLen++;
			}
			rightIndex++;
		} while ((rightIndex < numsSize) && ((nums[rightIndex] == 1) || (flips < k)));

		maxOnesLen = (onesLen > maxOnesLen) ? onesLen : maxOnesLen;

		do {
			onesLen -= nums[leftIndex];
			if ((nums[leftIndex] == 0) && (flips > 0)) {
				flips--;
				onesLen--;
				leftIndex++;
				break;
			}
			leftIndex++;
		} while ((leftIndex < rightIndex) && ((nums[leftIndex] == 1) || (flips > 0)));
	}
	return maxOnesLen;
}

int longestOnes(int* nums, int numsSize, int k) {
	return longestOnesSlidingWindow(nums, numsSize, k);
}