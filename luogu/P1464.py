m = {}


def w(a, b, c):
    global m

    item = (a, b, c)
    if item in m:
        return m[(a, b, c)]

    ret = None
    if a <= 0 or b <= 0 or c <= 0:
        ret = 1
    elif a > 20 or b > 20 or c > 20:
        ret = w(20, 20, 20)
    elif a < b and b < c:
        ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c)
    else:
        ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + \
            w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1)

    m[item] = ret
    return ret


if __name__ == "__main__":
    while True:
        a, b, c = map(int, input().split())
        if a == -1 and b == -1 and c == -1:
            break

        print(f"w({a}, {b}, {c}) = {w(a, b, c)}")
