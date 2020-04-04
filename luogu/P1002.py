if __name__ == "__main__":
    m = [[1] * 21 for i in range(21)]
    res = [[0] * 21 for i in range(21)]

    b_i, b_j, h_i, h_j = map(int, input().split())
    temp_i = [-2, 2]
    temp_j = [-1, 1]

    m[h_i][h_j] = 0

    for i in range(2):
        for j in range(2):
            if h_i + temp_i[i] >= 0 and h_i + temp_i[i] <= b_i \
                    and h_j + temp_j[j] >= 0 and h_j + temp_j[j] <= b_j:
                m[h_i + temp_i[i]][h_j + temp_j[j]] = 0

    for i in range(2):
        for j in range(2):
            if h_i + temp_j[i] >= 0 and h_i + temp_j[i] <= b_i \
                    and h_j + temp_i[j] >= 0 and h_j + temp_i[j] <= b_j:
                m[h_i + temp_j[i]][h_j + temp_i[j]] = 0

    for i in range(0, b_i + 1):
        if not m[i][0]:
            break
        res[i][0] = 1

    for j in range(0, b_j + 1):
        if not m[0][j]:
            break
        res[0][j] = 1

    for i in range(1, b_i + 1):
        for j in range(1, b_j + 1):
            if m[i][j]:
                res[i][j] = res[i - 1][j] + res[i][j - 1]

    print(res[b_i][b_j])
