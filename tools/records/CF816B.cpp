#include <iostream>

int n, k, q;
int l, r;
int a, b;

int arr1[200005];
int arr2[200005];

inline int last_bit(int num) {
    return num & (-num);
}

int sum(int* arr, int index) {
    int res = 0;
    while (index) {
        res += arr[index];
        index -= last_bit(index);
    }

    return res;
}

void add(int* arr, int index, int value) {
    while (index <= 200000) {
        arr[index] += value;
        index += last_bit(index);
    }
}

int between(int low, int high) {
    return sum(arr2, high) - sum(arr2, low - 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n >> k >> q;

    for (int i = 0; i != n; i++) {
        std::cin >> l >> r;
        add(arr1, l, 1);
        add(arr1, r + 1, -1);
    }

    for (int i = 0; i <= 200000; i++) {
        if (sum(arr1, i) >= k) {
            add(arr2, i, 1);
        }
    }

        for (int i = 0; i != q; i++) {
            std::cin >> a >> b;
            std::cout << between(a, b) << "\n";
        }
}