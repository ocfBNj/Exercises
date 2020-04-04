if __name__ == "__main__":
    n = int(input())
    id_ = [i + 1 for i in range(n)]
    time = list(map(int, input().split()))
    zipped = list(zip(id_, time))

    zipped.sort(key=lambda zipp: zipp[1])
    
    res = 0
    sum_ = 0
    print(zipped[0][0], end=" ")
    for i in range(1, n):
        print(zipped[i][0], end=" ")
        sum_ += zipped[i - 1][1]
        res += sum_

    print("\n%.2f" % (res / n))
