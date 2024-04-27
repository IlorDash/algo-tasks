from typing import List


class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        maxOnesLen = 0
        nullDropped = False
        i = 0

        # Loop over Zeros
        while (i < len(nums)) and (i >= 0):
            j = i + 1
            onesLen = nums[i]
            lastNullPos = -1
            nullDropped = False
            # Loop over Ones
            while (j < len(nums)) and (nums[j] != 0 or (not nullDropped)):
                onesLen += nums[j]
                lastNullPos = (
                    j if (nums[j] == 0) and (lastNullPos == -1) else lastNullPos
                )
                nullDropped = (
                    True if (nums[j] == 0 and not nullDropped) else nullDropped
                )
                j += 1

            onesLen -= 1 if (not nullDropped) and (nums[i] != 0) else 0
            i = lastNullPos
            maxOnesLen = max(onesLen, maxOnesLen)

        return maxOnesLen
