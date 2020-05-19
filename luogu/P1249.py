import sys

if __name__ == "__main__":
    n = int(input())
    sum_ = 0
    end = 0
    mu = 1
    num = 0
    for i in range(2, 10001):
        sum_ += i
        if sum_ >= n:
            end = i
            num = sum_ - n
            if num == 1:
                print(1, end=" ")
                num = 2
            break

    for i in range(2, end + 1):
        if i != num:
            mu *= i
            print(i, end=" ")

    print()
    print(mu)
