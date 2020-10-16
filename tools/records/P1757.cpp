#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstring>

int m, n;
int a, b, c;

struct obj_t {
    int w;
    int v;
};

obj_t objs[1005];
std::vector<obj_t*> groups[1005];

// arr[前i组][重量]
int arr[1005][1005];

int resolve() {
    // 对于每一组
    for (int i = 1; i <= 1000; i++) {
        if (groups[i].size() == 0) {
            std::memcpy(arr[i], arr[i - 1], sizeof arr[i - 1]);
            continue;
        }

        for (int j = 1; j <= m; j++) {
            int res = std::numeric_limits<int>::min();

            // 每组中的物品选或不选的最大值
            for (int k = 0; k != groups[i].size(); k++) {
                obj_t* obj = groups[i][k];

                if (obj->w > j) {
                    res = std::max(res, arr[i - 1][j]);
                } else {
                    res = std::max(res, std::max(arr[i - 1][j], arr[i - 1][j - obj->w] + obj->v));
                }
            }

            arr[i][j] = res;
        }
    }

    return arr[1000][m];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> m >> n;

    for (int i = 1; i <= n; i++) {
        std::cin >> a >> b >> c;
        objs[i] = {a, b};
        groups[c].push_back(&objs[i]);
    }

    std::cout << resolve() << "\n";
}