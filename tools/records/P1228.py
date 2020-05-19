def resolve(x1, y1, x2, y2, des_x, des_y):
    if x2 - x1 == 1 and y2 - y1 == 1:
        if des_x == x1 and des_y == y1:
            print(x2, y2, 1)
        elif des_x == x2 and des_y == y1:
            print(x1, y2, 3)
        elif des_x == x1 and des_y == y2:
            print(x2, y1, 2)
        elif des_x == x2 and des_y == y2:
            print(x1, y1, 4)

        return

    # 左上角
    mid_x = (x1 + x2) // 2
    mid_y = (y1 + y2) // 2

    if des_x <= mid_x and des_y <= mid_y:
        resolve(x1, y1, mid_x, mid_y, des_x, des_y)
        print(mid_x + 1, mid_y + 1, 1)

        resolve(mid_x + 1, y1, x2, mid_y, mid_x + 1, mid_y)
        resolve(mid_x + 1, mid_y + 1, x2, y2, mid_x + 1, mid_y + 1)
        resolve(x1, mid_y + 1, mid_x, y2, mid_x, mid_y + 1)
    elif des_x <= mid_x and des_y > mid_y:
        resolve(x1, mid_y + 1, mid_x, y2, des_x, des_y)

        print(mid_x + 1, mid_y, 2)
        resolve(x1, y1, mid_x, mid_y, mid_x, mid_y)
        resolve(mid_x + 1, y1, x2, mid_y, mid_x + 1, mid_y)
        resolve(mid_x + 1, mid_y + 1, x2, y2, mid_x + 1, mid_y + 1)
    elif des_x > mid_x and des_y <= mid_y:
        resolve(mid_x + 1, y1, x2, mid_y, des_x, des_y)
        print(mid_x, mid_y + 1, 3)

        resolve(mid_x + 1, mid_y + 1, x2, y2, mid_x + 1, mid_y + 1)
        resolve(x1, y1, mid_x, mid_y, mid_x, mid_y)
        resolve(x1, mid_y + 1, mid_x, y2, mid_x, mid_y + 1)
    elif des_x > mid_x and des_y > mid_y:
        resolve(mid_x + 1, mid_y + 1, x2, y2, des_x, des_y)
        print(mid_x, mid_y, 4)

        resolve(x1, y1, mid_x, mid_y, mid_x, mid_y)
        resolve(x1, mid_y + 1, mid_x, y2, mid_x, mid_y + 1)
        resolve(mid_x + 1, y1, x2, mid_y, mid_x + 1, mid_y)


if __name__ == "__main__":
    k = int(input())
    x, y = map(int, input().split())
    resolve(1, 1, 2 ** k, 2 ** k, x, y)
