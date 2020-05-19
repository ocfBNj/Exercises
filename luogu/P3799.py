import math

dic = [0] * 5001
mod = 1000000007


def C(n, m):
    return n if m == 1 else n * (n - 1) // 2 % mod


if __name__ == "__main__":
    n = int(input())
    res = 0

    for i in range(n):
        dic[int(input())] += 1

    for num in range(2, 5001):
        count = dic[num]

        if count >= 2:
            temp = C(count, 2)

            for i in range(1, num // 2 + 1):
                j = num - i

                if i == j and dic[i] >= 2:
                    res = (res + temp * C(dic[i], 2)) % mod
                if i != j and dic[j] >= 1 and dic[i] >= 1:
                    res = (res + temp * C(dic[i], 1) %
                           mod * C(dic[j], 1) % mod) % mod

    print(res)
