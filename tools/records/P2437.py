if __name__ == "__main__":
    m, n = map(int, input().split())

    a, b = 1, 1
    for i in range(1, n - m):
        a, b = b, a + b
    
    b = 0 if n - m < 0 else b
    print(b)
