class Number:
    def __init__(self, string):
        self.s = string

    def __lt__(self, other):
        len_s = len(self.s)
        len_o = len(other.s)

        if len_s == len_o:
            return self.s < other.s
        elif len_s < len_o:
            ret = self.s[:len_s] == other.s[:len_s]
            if ret:
                return other.s[len_s] > other.s[0]
            else:
                return self.s[:len_s] < other.s[:len_s]
        else:
            ret = self.s[:len_o] == other.s[:len_o]
            if ret:
                return self.s[len_o] < self.s[0]
            else:
                return self.s[:len_o] < other.s[:len_o]


if __name__ == "__main__":
    n = int(input())
    numbers = list(map(Number, input().split()))
    numbers.sort(reverse=True)
    for number in numbers:
        print(number.s, end="")
    print()
