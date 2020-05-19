if __name__ == "__main__":
    q = int(input())

    for _ in range(q):
        n = int(input())
        pushed = list(map(int, input().split()))
        poped = list(map(int, input().split()))
        s = []
        i = 0

        for j in range(n):
            s.append(pushed[j])

            while len(s) > 0 and s[-1] == poped[i]:
                s.pop()
                i += 1

        if len(s) == 0:
            print("Yes")
        else:
            print("No")
