import math


def reslove(number):
    if number == 0:
        return str(number)

    sum = 0
    ret = ""
    while sum != number:
        c = math.floor(math.log2(number - sum))
        sum += 2**c
        if c == 1:
            ret += f"2+"
        else:
            ret += f"2({reslove(c)})+"

    return ret[:-1]


if __name__ == "__main__":
    n = int(input())
    print(reslove(n))
