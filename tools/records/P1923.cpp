#include <iostream>
#include <algorithm>

int n, k;
int arr[5000005];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n >> k;

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::nth_element(arr, arr + k, arr + n);
    std::cout << arr[k] << "\n";
}
