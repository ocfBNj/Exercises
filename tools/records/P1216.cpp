#include <iostream>
#include <algorithm>

int arr[1000][1000];
int n;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cin >> arr[i][j];
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            arr[n - 1][j] = arr[i][j] + std::max(arr[n - 1][j], arr[n - 1][j + 1]);
        }
    }

    std::cout << arr[n - 1][0] << "\n";    
}
