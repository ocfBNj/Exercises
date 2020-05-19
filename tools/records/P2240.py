if __name__ == "__main__":
    N, T = map(int, input().split())
    arr = [None] * N
    res = 0

    for i in range(N):
        arr[i] = tuple(map(int, input().split()))

    arr.sort(key=lambda tp: tp[1]/tp[0], reverse=True)
    
    cur_t = 0
    i = 0
    while i < len(arr):
        if cur_t + arr[i][0] > T:
            break
        res += arr[i][1]
        cur_t += arr[i][0]
        i += 1

    if i < len(arr) and cur_t < T:
        res += (T - cur_t) * (arr[i][1] / arr[i][0])
    
    print("%.2f" % res)
