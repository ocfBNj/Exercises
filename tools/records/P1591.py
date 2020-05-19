if __name__ == "__main__":
    t = int(input())

    store = [0] * 10001
    store[0] = 1
    for i in range(1, 1001):
        store[i] = i * store[i - 1]

    for _ in range(t):
        n, a = map(int, input().split())
        print(str(store[n]).count(str(a)))
