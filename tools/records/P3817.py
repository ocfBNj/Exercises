if __name__ == "__main__":
    n, x = map(int, input().split())
    arr = list(map(int, input().split()))
    res = 0

    for i in range(n):
        if i == 0:
            if arr[i] > x:
                res += arr[i] - x
                arr[i] = x
        else:
            if arr[i] + arr[i - 1] > x:
                count = arr[i] + arr[i - 1] - x
                res += count
                arr[i] -= count

    print(res)
