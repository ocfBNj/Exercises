#include <iostream>

int arr[50][50];
char used[50][50];
int m, n;
int max;
int max_count;
int count;

void resolve(int i, int j) {
    if (used[i][j]) return;
    used[i][j] = 1;

    if (++max_count > max) max = max_count;

    if (!(arr[i][j] & 1)) resolve(i, j - 1);
    if (!(arr[i][j] & 2)) resolve(i - 1, j);
    if (!(arr[i][j] & 4)) resolve(i, j + 1);
    if (!(arr[i][j] & 8)) resolve(i + 1, j);
}

int main() {
    std::cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!used[i][j]) {
                max_count = 0;
                count++;
                resolve(i, j);
            }
        }
    }

    std::cout << count << " " << max << "\n";
}
