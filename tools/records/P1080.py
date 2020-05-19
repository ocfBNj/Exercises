if __name__ == "__main__":
    n = int(input())
    a, b = map(int, input().split())

    arr = []
    for _ in range(n):
        arr.append(tuple(map(int, input().split())))

    arr.sort(key=lambda item: item[0] * item[1])


    max_ = 0

    for i in range(n):
        res = a
        for item in arr[:i]:
            res *= item[0]
        res //= arr[i][1]

        if res > max_:
            max_ = res

    print(int(max_))
