if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    res = arr[0]
    for i in range(1, n):
        if arr[i] > arr[i - 1]:
            res += arr[i] - arr[i - 1]

    print(res)
