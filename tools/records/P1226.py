def is_set(b, i) -> bool:
    return b & (1 << i)

def reslove(a, b, n):
    c = 0
    d = 1

    i = 31
    while i >= 0:
        c = 2 * c
        d = (d**2) % n
        if is_set(b, i):
            c += 1
            d = (d * a) % n
        i -= 1
    
    return d

if __name__ == "__main__":
    a, b, n = map(int, input().split())
    print(f"{a}^{b} mod {n}={reslove(a, b, n)}")
