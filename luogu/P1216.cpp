#include <iostream>
#include <algorithm>

int arr[1000][1000];
int saved[1000][1000];
int n;

int resolve1(int i, int j) {
    if (i >= n) return 0;
    if (saved[i][j] != -1) return saved[i][j];

    int sum1 = arr[i][j] + resolve1(i + 1, j);
    int sum2 = arr[i][j] + resolve1(i + 1, j + 1);
    saved[i][j] = std::max(sum1, sum2);

    return saved[i][j];
}

inline int resolve2(int, int) {
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            arr[n - 1][j] = arr[i][j] + std::max(arr[n - 1][j], arr[n - 1][j + 1]);
        }
    }

    return arr[n - 1][0];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cin >> arr[i][j];
        }
        std::fill(saved[i], saved[i] + n, -1);
    }
    
    std::cout << resolve1(0, 0) << "\n";    
}
