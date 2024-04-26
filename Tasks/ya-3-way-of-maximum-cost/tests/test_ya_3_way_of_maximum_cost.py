import pytest

from src.ya_3_way_of_maximum_cost import max_cost_way


@pytest.mark.parametrize(
    "rows, cols, arr, ans, route",
    [
        (
            5,
            5,
            [
                [9, 9, 9, 9, 9],
                [3, 0, 0, 0, 0],
                [9, 9, 9, 9, 9],
                [6, 6, 6, 6, 8],
                [9, 9, 9, 9, 9],
            ],
            74,
            "D D R R R R D D",
        ),
        (
            1,
            1,
            [
                [1],
            ],
            1,
            "",
        ),
        (
            3,
            4,
            [
                [0, 0, 0, 0],
                [0, 0, 0, 0],
                [0, 0, 0, 0],
            ],
            0,
            "D D R R R",
        ),
        (
            3,
            3,
            [
                [0, 0, 0],
                [0, 0, 0],
                [0, 0, 0],
            ],
            0,
            "D D R R",
        ),
    ],
)
def test_ya_3_the_way_of_maximum_cost(rows, cols, arr, ans, route):
    assert max_cost_way(arr, rows, cols) == [ans, route]
