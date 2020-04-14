#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>

struct Pos {
    double x;
    double y;
};

Pos arr[16];
double saved_dis[16][16];
double saved_res[16][65536];
int n;

inline double distance(int i, int j) {
    if (saved_dis[i][j]) {
        return saved_dis[i][j];
    };

    const Pos& src = arr[i];
    const Pos& des = arr[j];
    saved_dis[i][j] = std::sqrt((src.x - des.x) * (src.x - des.x)
                            + (src.y - des.y) * (src.y - des.y));
    return saved_dis[i][j];
}

inline unsigned short set(unsigned short points, int i) {
    return points | (1 << i);
}

inline unsigned short reset(unsigned short points, int i) {
    return points & ~(1 << i);
}

inline bool test(unsigned short points, int i) {
    return points & (1 << i);
}

// 求：从点arr[curPoxI]出发，剩余的点为points，距离最短的结果
double resolve(int curPosI, unsigned short points) {
    if (points == 0) return 0;
    if (saved_res[curPosI][points]) return saved_res[curPosI][points];

    double ret = std::numeric_limits<double>::max();

    for (int i = 1; i <= n; i++) {
        if (test(points, i)) {
            ret = std::min(distance(curPosI, i) + resolve(i, reset(points, i)), ret);
        }
    }

    saved_res[curPosI][points] = ret;
    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n;
    Pos start = {0, 0};
    arr[0] = start;

    unsigned short points = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> arr[i].x >> arr[i].y;
        points = set(points, i);
    }

    std::cout.setf(std::ios_base::fixed);
    std::cout.precision(2);
    std::cout << resolve(0, points) << "\n";
}
