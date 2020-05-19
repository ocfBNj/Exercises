def swap1(string, i, j) -> str:
    return string[:i - 1] + "--" + string[i + 1:j - 1] + "o*" + string[j + 1:]


def swap2(string, i, j) -> str:
    return string[:i - 1] + "**" + string[i + 1:j - 1] + "--" + string[j + 1:]


if __name__ == "__main__":
    n = int(input())
    string = "o"*n + "*"*n + "--"

    print(string)
    while n > 4:
        string = swap1(string, n, 2*n + 1)
        print(string)
        string = swap2(string, n, 2*n - 1)
        print(string)
        n -= 1

    # n <= 4
    print("ooo--***o*" + string[10:])
    print("ooo*o**--*" + string[10:])
    print("o--*o**oo*" + string[10:])
    print("o*o*o*--o*" + string[10:])
    print("--o*o*o*o*" + string[10:])
