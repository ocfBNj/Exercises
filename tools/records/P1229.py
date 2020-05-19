if __name__ == "__main__":
    prev = input()
    last = input()
    res = 1

    for i in range(0, len(prev) - 1):
        for j in range(1, len(last)):
            if prev[i] == last[j] and prev[i + 1] == last[j - 1]:
                res *= 2

    print(res)
