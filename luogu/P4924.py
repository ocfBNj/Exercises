def rotate(x, y, r, dir):
    global map_, right_left, bottom_up
    if r == 0:
        return

    for i in range(2):
        for j in range(2*r+1):
            c = 1 if i == 0 else -1
            right_left[i][j] = map_[x - r + j][y + c*r]
            bottom_up[i][j] = map_[x + c*r][y - r + j]

    if dir == 0:
        for i in range(2*r + 1):
            map_[x - r][y - r + i] = right_left[1][2*r - i]
        for i in range(2*r + 1):
            map_[x - r + i][y + r] = bottom_up[1][i]
        for i in range(2*r + 1):
            map_[x + r][y + r - i] = right_left[0][i]
        for i in range(2*r + 1):
            map_[x + r - i][y - r] = bottom_up[0][2*r - i]
    else:
        for i in range(2*r + 1):
            map_[x - r][y - r + i] = right_left[0][i]
        for i in range(2*r + 1):
            map_[x - r + i][y + r] = bottom_up[0][2*r - i]
        for i in range(2*r + 1):
            map_[x + r][y + r - i] = right_left[1][2*r - i]
        for i in range(2*r + 1):
            map_[x + r - i][y - r] = bottom_up[1][i]

    rotate(x, y, r - 1, dir)


if __name__ == "__main__":
    n, m = map(int, input().split())

    map_ = [[0] * (n + 1) for _ in range(n + 1)]
    # 从上到下拷贝
    right_left = [[0] * 505 for _ in range(2)]
    # 从左到右拷贝
    bottom_up = [[0] * 505 for _ in range(2)]

    temp = 1

    for i in range(1, n + 1):
        for j in range(1, n + 1):
            map_[i][j] = temp
            temp += 1

    for _ in range(m):
        x, y, r, z = map(int, input().split())
        rotate(x, y, r, z)

    for i in range(1, n + 1):
        for j in range(1, n + 1):
            print(map_[i][j], end=" ")
        print()
