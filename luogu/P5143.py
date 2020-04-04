from math import sqrt


def distance(p1, p2) -> float:
    return sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2 + (p1[2] - p2[2])**2)


if __name__ == "__main__":
    points = []
    n = int(input())
    res = 0

    for i in range(n):
        x, y, z = map(int, input().split())
        points.append((x, y, z))

    points.sort(key=lambda point: point[2])

    for i in range(1, n):
        res += distance(points[i - 1], points[i])

    print("%.3f" % res)
