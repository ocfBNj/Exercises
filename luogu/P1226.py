def is_set(b, i) -> bool:
    return b & (1 << i)

def resolve(a, b, n):
    d = 1
    i = 31

    while i >= 0:
        d = (d * d) % n
        if is_set(b, i):
            d = (d * a) % n
        i -= 1
    
    return d

if __name__ == "__main__":
    a, b, n = map(int, input().split())
    print(f"{a}^{b} mod {n}={resolve(a, b, n)}")
