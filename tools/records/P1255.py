if __name__ == "__main__":
    n = int(input())

    a, b = 1, 1
    for i in range(1, n):
        a, b = b, a + b
    
    b = 0 if n == 0 else b
    print(b)
