#include <iostream>

int arr[1000005];

inline int lower_bound(int first, int last, int value) {
    int count = last - first;
    int step;
    while (count > 0) {
        step = count / 2;
        if (arr[first + step] < value) {
            first += step + 1;
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

    int ret;
    for (int i = 0; i < m; i++) {
        std::cin >> number;
        ret = lower_bound(0, n, number);
        if (ret == -1 || arr[ret] != number) {
            std::cout << "-1 ";
        } else {
            std::cout << ret + 1 << " ";
        }
        
    }
}
