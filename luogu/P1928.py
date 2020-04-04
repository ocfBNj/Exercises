def decode(string):
    begin = -1
    end = -1
    for i, c in enumerate(string):
        if c == '[':
            begin = i
        elif c == ']':
            end = i
            break

    if begin == -1:
        return string
    else:
        left = string[:begin]
        mid = string[begin + 1:end]

        i = 0
        while True:
            if not str.isdigit(mid[i]):
                break
            i += 1

        mid = mid[i:] * int(mid[:i])

        right = string[end + 1:]

        return decode(left + mid + right)


if __name__ == "__main__":
    string = input()
    print(decode(string))
