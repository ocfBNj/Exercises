if __name__ == "__main__":
    string, n = input().split()
    n = int(n)
    length = len(string)

    i = length
    while i < n:
        i *= 2

    while n > length:
        mid = i // 2
        
        if n > mid + 1:
            n = n - mid - 1
        elif n == mid + 1:
            n = mid

        i //= 2


    print(string[n - 1])
