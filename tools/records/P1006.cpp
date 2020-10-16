#include <algorithm>
#include <iostream>

int arr[52][52];
int res[52][52][52][52];
int m, n;

void resolve() {
    for (int i1 = 1; i1 <= m; i1++) {
        for (int j1 = 1; j1 <= n; j1++) {
            for (int i2 = 1; i2 <= m; i2++) {
                for (int j2 = 1; j2 <= n; j2++) {
                    res[i1][j1][i2][j2] =
                        std::max({res[i1 - 1][j1][i2 - 1][j2],
                                  res[i1][j1 - 1][i2 - 1][j2],
                                  res[i1 - 1][j1][i2][j2 - 1],
                                  res[i1][j1 - 1][i2][j2 - 1]}) +
                        arr[i1][j1] + arr[i2][j2];

                    if (i1 == i2 && j1 == j2) {
                        if (i1 == m && j1 == n) {
                            continue;
                        } else {
                            res[i1][j1][i2][j2] = 0;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> arr[i][j];
        }
    }

    resolve();

    std::cout << res[m][n][m][n] << "\n";
}