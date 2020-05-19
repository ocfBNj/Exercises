import array

def fill(line):
    global map_, m, n

    for k in range(m):
        count = 0
        for i in range(-1, 2, 1):
            for j in range(-1, 2, 1):
                if line + i < n and line + i >= 0 and k + j < m and k + j >= 0 and (i != 0 or j != 0):
                    if map_[line + i][k + j] == "*":
                        count += 1

        if map_[line][k] != "*":
            map_[line][k] = str(count)

if __name__ == "__main__":
    n, m = map(int, input().split())
    map_ = [None] * n
    for i in range(n):
        map_[i] = array.array('u', input())
    
    for i, line in enumerate(map_):
        fill(i)
        print(line.tounicode())
