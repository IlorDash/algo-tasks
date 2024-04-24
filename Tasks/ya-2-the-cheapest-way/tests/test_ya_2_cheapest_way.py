import pytest

from src.ya_2_cheapest_way import cheapest_way


@pytest.mark.parametrize(
    "rows, cols, arr, ans",
    [
        (
            5,
            5,
            [
                [1, 1, 1, 1, 1],
                [3, 100, 100, 100, 100],
                [1, 1, 1, 1, 1],
                [2, 2, 2, 2, 1],
                [1, 1, 1, 1, 1],
            ],
            11,
        ),
        (
            1,
            1,
            [
                [1],
            ],
            1,
        ),
        (
            3,
            4,
            [
                [0, 0, 0, 0],
                [0, 0, 0, 0],
                [0, 0, 0, 0],
                [0, 0, 0, 0],
            ],
            0,
        ),
    ],
)
def test_ya_2_cheapest_way(rows, cols, arr, ans):
    assert cheapest_way(arr, rows, cols) == ans
