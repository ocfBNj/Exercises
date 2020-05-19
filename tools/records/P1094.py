if __name__ == "__main__":
    w = int(input())
    n = int(input())
    arr = [0] * n

    for i in range(n):
        arr[i] = int(input())

    arr.sort()

    i, j = 0, n - 1
    res = 0

    while arr[i] <= w and i <= j:
        if i == j and arr[i] <= w:
            res += 1
            break

        if arr[i] + arr[j] <= w:
            res += 1
            i += 1
            j -= 1
        elif arr[j] <= w:
            res += 1
            j -= 1

    print(res)
