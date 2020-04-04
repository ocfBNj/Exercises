res = 0
n = None
m = None
a = None


def resolve(count, begin):
    global res, n, m, a
    if count == m:
        res += 1
        return
    if count > m:
        return

    for i in range(begin, n):
        resolve(a[i] + count, i + 1)


if __name__ == "__main__":
    n, m = map(int, input().split())
    a = []
    i = 0
    while i < n:
        temp = list(map(int, input().split()))
        a += temp
        i += len(temp)
    a.sort(reverse=True)
    resolve(0, 0)
    print(res)
