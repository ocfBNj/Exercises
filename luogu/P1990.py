if __name__ == "__main__":
    n = int(input())
    arr = [[0] * 2 for i in range(3)]

    arr[0][0] = 1

    arr[1][0] = 2
    arr[1][1] = 2

    for _ in range(3, n + 1):
        arr[2][0] = (arr[1][0] + arr[1][1] + arr[0][0]) % 10000
        arr[2][1] = (arr[1][1] + arr[0][0] * 2) % 10000
        arr[0][0], arr[0][1], arr[1][0], arr[1][1] = \
            arr[1][0], arr[1][1], arr[2][0], arr[2][1]

    print(arr[2][0])
