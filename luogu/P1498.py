if __name__ == "__main__":
    n = int(input())
    arr = [0] * 2000
    arr[0] = 1

    for i in range(2 ** n):
        print(" "*((2 ** n) - 1 - i), end="")
        for j in range(i, -1, -1):
            arr[j] ^= arr[j - 1]
        if i % 2:
            for j in range(0, i + 1, 2):
                if arr[j] and arr[j + 1]:
                    print("/__\\", end="")
                else:
                    print("    ", end="")
        else:
            for j in range(i + 1):
                if arr[j]:
                    print("/\\", end="")
                else:
                    print("  ", end="")
        print()
