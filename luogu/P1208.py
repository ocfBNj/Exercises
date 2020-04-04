if __name__ == "__main__":
    m, n = map(int, input().split())
    arr = [None] * n
    for i in range(n):
        p, a = map(int, input().split())
        arr[i] = (p, a)

    arr.sort(key=lambda item: item[0])
    count, i = 0, 0
    res = 0

    while count < m:
        count += arr[i][1]
        res += arr[i][0] * arr[i][1]
        i += 1
    
    if count > m:
        i -= 1
        res -= (count - m) * arr[i][0]

    print(res)
