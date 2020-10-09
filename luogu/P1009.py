if __name__ == "__main__":
    n = int(input())
    res = 1
    temp = 1

    for i in range(2, n + 1):
        temp *= i
        res += temp

    print(res)
