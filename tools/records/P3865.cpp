#include <algorithm>
#include <cmath>
#include <iostream>

int n, m;
int arr[100000];
int sparse_table[100000][17];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();

    while (!isdigit(ch)) {
        if (ch == '-') {
            f = -1;
        }
        ch = getchar();
    }

    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }

    return x * f;
}

void construct_sparse_table() {
    for (int i = 0; i != n; i++) {
        sparse_table[i][0] = arr[i];
    }

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            sparse_table[i][j] = std::max(sparse_table[i][j - 1], sparse_table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int range_maximum_query(int low, int high) {
    int l = high - low + 1;
    int k = static_cast<int>(std::floor(std::log2(l)));

    return std::max(sparse_table[low][k], sparse_table[low + l - (1 << k)][k]);
}

int main() {
    std::cin >> n >> m;

    for (int i = 0; i != n; i++) {
        arr[i] = read();
    }

    construct_sparse_table();

    int l, r;
    for (int i = 0; i != m; i++) {
        l = read();
        r = read();

        std::cout << range_maximum_query(l - 1, r - 1) << "\n";
    }
}