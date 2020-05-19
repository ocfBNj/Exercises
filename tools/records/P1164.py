if __name__ == "__main__":
    n, m = map(int, input().split())
    a = []
    i = 0
    while i < n:
        temp = list(map(int, input().split()))
        a += temp
        i += len(temp)

    dp = [0] * (m + 1)
    dp[0] = 1

    for i in range(1, n + 1):
        for j in range(m, a[i - 1] - 1, -1):
            dp[j] += dp[j - a[i - 1]]        
            
    print(dp[m])
