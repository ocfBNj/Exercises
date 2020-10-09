#include <algorithm>
#include <iostream>

int arr[100005];

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::sort(arr, arr + n);

    int time = 0; // 等待时间
    int res = 0;

    for (int i = 0; i < n; i++) {
        if (time <= arr[i]) {
            res++;
            time += arr[i];
        }
    }

    std::cout << res << std::endl;
}
