import pytest

from src.longest_subarr_of_ones_after_deleting_one_element import Solution


@pytest.mark.parametrize(
    "nums, ans",
    [
        # Input: nums = [1,1,0,1]
        # Output: 3
        # Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
        (
            [1, 1, 0, 1],
            3,
        ),
        # Input: nums = [0,1,1,1,0,1,1,0,1]
        # Output: 5
        # Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
        (
            [0, 1, 1, 1, 0, 1, 1, 0, 1],
            5,
        ),
        # Input: nums = [1,1,1]
        # Output: 2
        # Explanation: You must delete one element.
        (
            [1, 1, 1],
            2,
        ),
        # Input: nums = [1,1,0,0,1,1,1,0,1]
        # Output: 2
        # Explanation: You must delete one element.
        (
            [1, 1, 0, 0, 1, 1, 1, 0, 1],
            4,
        ),
        # Input: nums = [0,1,1,1,1,1]
        # Output: 5
        # Explanation: You must delete one element.
        (
            [0, 1, 1, 1, 1, 1],
            5,
        ),
    ],
)
def test_ya_2_cheapest_way(nums, ans):
    my_solution = Solution()
    assert my_solution.longestSubarray(nums) == ans
