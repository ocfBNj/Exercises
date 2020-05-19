#include <iostream>
#include <algorithm>
#include <numeric>

int arr[1000005];

int lower_bound(int first, int last, int value) {
    int count = last - first;
    int step;
    while (count > 0) {
        step = count / 2;
        if (arr[first + step] < value) {
            first += ++step;
            count -= step + 1;
        } else {
            count = step;
        }
    }
    return first == last ? -1 : first;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n, m;
    int number;

    std::cin >> n >> m;

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        std::cin >> number;
        auto ret = std::lower_bound(arr, arr + n, number);
        if (*ret == number) {
            std::cout << ret - arr + 1 << " ";
        } else {
            std::cout << "-1 ";
        }
    }
}
