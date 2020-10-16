arr = []

record = {}


def get(n, i, j, k):
    """对于第n行，左边在i处，右边在j处，第k次取数的最大值"""
    global arr, record

    if (i, j, k) in record:
        return record[(i, j, k)]

    if i == j:
        return arr[n][i] * (2**k)

    record[(i, j, k)] = max(
        arr[n][i] * (2**k) + get(n, i + 1, j, k + 1),
        arr[n][j] * (2**k) + get(n, i, j - 1, k + 1)
    )

    return record[(i, j, k)]


def resolve():
    global n, m, record

    res = 0
    # 每行分别取数，相加即为结果
    for i in range(n):
        record = {}
        res += get(i, 0, m - 1, 1)

    return res


if __name__ == "__main__":
    n, m = map(int, input().split())

    for i in range(n):
        arr.append(list(map(int, input().split())))

    print(resolve())
