#include <iostream>

char map[101][101];
int n, m;
int res;

void resolve(int i, int j) {
    if (i >= 0 && j >= 0 && i < n && j < m && map[i][j] == 'W') {
        map[i][j] = res;
        resolve(i - 1, j);
        resolve(i + 1, j);
        resolve(i, j + 1);
        resolve(i, j - 1);
        resolve(i + 1, j + 1);
        resolve(i + 1, j - 1);
        resolve(i - 1, j + 1);
        resolve(i - 1, j - 1);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'W') {
                res++;
                resolve(i, j);
            }
        }
    }

    std::cout << res << "\n";
}
