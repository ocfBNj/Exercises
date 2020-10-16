import math


def resolve(num: str, k: int) -> int:
    arr = [[1] * (k + 1) for _ in range(len(num) + 1)]

    # 切割次数为0
    for i in range(1, len(num) + 1):
        arr[i][0] = int(num[:i])

    # 问题规模[1, n]
    for n in range(1, len(num) + 1):
        # 切割次数为[1, k]
        for i in range(1, k + 1):
            res = -math.inf

            # 切割距离[1, n - 1]
            for j in range(1, n):
                # 在离起点距离为j处切割
                res = max(res, arr[j][i - 1] * int(num[j:n]))
            arr[n][i] = res

    return arr[len(num)][k]


if __name__ == "__main__":
    n, k = map(int, input().split())
    num = input()

    print(resolve(num, k))
