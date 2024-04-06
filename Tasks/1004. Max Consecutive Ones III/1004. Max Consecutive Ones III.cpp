#include "1004. Max Consecutive Ones III.h"

#include "pch.h"

int calcLongestOnesSubArr(int* nums, int numsSize) {
	int onesLen = nums[0];;
	int maxLen = 0;
	for (int i = 1; i < numsSize; i++) {
		if (nums[i] == 0) {
			maxLen = (onesLen > maxLen) ? onesLen : maxLen;
			onesLen = 0;
		} else {
			onesLen++;
		}
	}
	maxLen = (onesLen > maxLen) ? onesLen : maxLen;
	return maxLen;
}

int findZeroFrom(int* nums, int numsSize, int from) {
	int res = -1;
	for (int i = from; i < numsSize; i++) {
		if (nums[i] == 0) {
			res = i;
			break;
		}
	}
	return res;
}

int longestOnesRecursion(int* nums, int numsSize, int pos, int kNum, int k) {
	if (kNum == k) {
		return calcLongestOnesSubArr(nums, numsSize);
	}
	int zeroPos = findZeroFrom(nums, numsSize, pos);
	if (zeroPos == -1) {
		return calcLongestOnesSubArr(nums, numsSize);
	}
	int tempMaxLen, maxLen = 0;
	while (zeroPos != -1) {
		nums[zeroPos] = 1;
		tempMaxLen = longestOnesRecursion(nums, numsSize, zeroPos + 1, kNum + 1, k);
		maxLen = (tempMaxLen > maxLen) ? tempMaxLen : maxLen;
		nums[zeroPos] = 0;
		zeroPos = findZeroFrom(nums, numsSize, zeroPos + 1);
	}
	return maxLen; 
}

int longestOnes(int* nums, int numsSize, int k) {
	return longestOnesRecursion(nums, numsSize, 0, 0, k);
}