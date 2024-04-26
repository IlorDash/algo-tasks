import sys


class Cell:
    def __init__(self, num=0, string=""):
        self.sum = num
        self.route = string


def max_cost_way(edge_w, rows, cols):
    dp = [[Cell() for i in range(cols)] for j in range(rows)]
    dp[0][0] = Cell(edge_w[0][0], "")
    for i in range(rows):
        for j in range(cols):
            # Right
            if j + 1 < cols:
                if (dp[i][j].sum + edge_w[i][j + 1]) >= dp[i][j + 1].sum:
                    dp[i][j + 1] = Cell(
                        dp[i][j].sum + edge_w[i][j + 1], dp[i][j].route + "R "
                    )
            # Down
            if i + 1 < rows:
                if (dp[i][j].sum + edge_w[i + 1][j]) >= dp[i + 1][j].sum:
                    dp[i + 1][j] = Cell(
                        dp[i][j].sum + edge_w[i + 1][j], dp[i][j].route + "D "
                    )
    dp[rows - 1][cols - 1].route = dp[rows - 1][cols - 1].route[:-1]
    return [dp[rows - 1][cols - 1].sum, dp[rows - 1][cols - 1].route]


def main():
    """
    Для чтения входных данных необходимо получить их
    из стандартного потока ввода (sys.stdin).
    Данные во входном потоке соответствуют описанному
    в условии формату. Обычно входные данные состоят
    из нескольких строк.
    Можно использовать несколько методов:
    * input() -- читает одну строку из потока без символа
    перевода строки;
    * sys.stdin.readline() -- читает одну строку из потока,
    сохраняя символ перевода строки в конце;
    * sys.stdin.readlines() -- вернет список (list) строк,
    сохраняя символ перевода строки в конце каждой из них.
    Чтобы прочитать из строки стандартного потока:
    * число -- int(input()) # в строке должно быть одно число
    * строку -- input()
    * массив чисел -- map(int, input().split())
    * последовательность слов -- input().split()
    Чтобы вывести результат в стандартный поток вывода (sys.stdout),
    можно использовать функцию print() или sys.stdout.write().
    Возможное решение задачи "Вычислите сумму чисел в строке":
    print(sum(map(int, input().split())))
    """
    rows, cols = list(map(int, input().split()))
    arr = [[0] * cols] * rows
    for i in range(rows):
        arr[i] = list(map(int, input().split()))

    ans = max_cost_way(arr, rows, cols)

    print(f"{ans[0]}\n{ans[1]}")

    return 0


if __name__ == "__main__":
    main()
