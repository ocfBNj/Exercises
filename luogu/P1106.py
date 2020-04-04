if __name__ == "__main__":
    number = list(input().rstrip())
    n = int(input())
    begin = 0
    while n > 0:
        while number[begin] == '0':
            del number[begin]

        if len(number) < begin + 3:
            break

        max_index = number.index(max(number[begin:begin+3]))

        if begin+3 < len(number) and min(number[begin+3:]) > number[max_index]:
            begin += 3
            continue

        if max_index == 2:
            max_index = begin if number[begin] > number[begin+1] else max_index
            if max_index == begin+2 and max_index + 1 < len(number) and number[max_index + 1] > number[max_index]:
                max_index += 1

        del number[max_index]
        n -= 1

    while n > 0:
        del number[number.index(max(number))]
        n -= 1
    print("".join(number))
