#include <algorithm>
#include <iostream>

int arr[10][10];
int res[10][10][10][10];
int n;
int x, y, v;

void resolve() {
    for (int i1 = 1; i1 <= n; i1++) {
        for (int j1 = 1; j1 <= n; j1++) {
            for (int i2 = 1; i2 <= n; i2++) {
                for (int j2 = 1; j2 <= n; j2++) {
                    res[i1][j1][i2][j2] = std::max({
                        res[i1 - 1][j1][i2 - 1][j2],
                        res[i1][j1 - 1][i2 - 1][j2],
                        res[i1 - 1][j1][i2][j2 - 1],
                        res[i1][j1 - 1][i2][j2 - 1]
                    }) + arr[i1][j1] + arr[i2][j2];

                    if (i1 == i2 && j1 == j2) {
                        res[i1][j1][i2][j2] -= arr[i1][j1];
                    }
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin >> n;
    for (;;) {
        std::cin >> x >> y >> v;

        if (x == 0 && y == 0 && v == 0) {
            break;
        }

        arr[x][y] = v;
    }

    resolve();

    std::cout << res[n][n][n][n] << "\n";
}