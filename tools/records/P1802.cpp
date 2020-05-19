#include <iostream>
#include <algorithm>

int n, x;
int lose[1001];
int win[1001];
int use[1001];
int arr[1001][10001];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n >> x;

    for (int i = 0; i < n; i++) {
        std::cin >> lose[i] >> win[i] >> use[i];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (j >= use[i - 1]) {
                // 打得过，打或不打
                arr[i][j] = std::max(arr[i - 1][j - use[i - 1]] + win[i - 1],
                                     arr[i - 1][j] + lose[i - 1]);
            } else {
                // 打不过
                arr[i][j] = arr[i - 1][j] + lose[i - 1];
            }
        }
    }

    std::cout << arr[n][x] * 5ULL << "\n";
}
