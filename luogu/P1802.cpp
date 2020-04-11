#include <iostream>
#include <algorithm>

int n, x;
int lose[1001];
int win[1001];
int use[1001];
int arr[10001];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n >> x;

    for (int i = 0; i < n; i++) {
        std::cin >> lose[i] >> win[i] >> use[i];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= 0; j--) {
            if (j >= use[i - 1]) {
                // 打得过，打或不打
                arr[j] = std::max(arr[j - use[i - 1]] + win[i - 1],
                                     arr[j] + lose[i - 1]);
            } else {
                // 打不过
                arr[j] = arr[j] + lose[i - 1];
            }
        }
    }

    std::cout << arr[x] * 5ULL << "\n";
}
