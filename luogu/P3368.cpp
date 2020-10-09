#include <iostream>

int n, m;
int arr[500001];

inline int last_bit(int num) {
    return num & (-num);
}

// return the sum of [1, index]
int sum(int index) {
    int res = 0;
    while (index) {
        res += arr[index];
        index -= last_bit(index);
    }

    return res;
}

// add value to the element of index of arr
void add(int index, int value) {
    while (index <= n) {
        arr[index] += value;
        index += last_bit(index);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n >> m;

    int value, last_value = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> value;
        add(i, value - last_value);

        last_value = value;
    }

    int op;
    int x, y, k;

    for (int i = 0; i != m; i++) {
        std::cin >> op;

        switch (op) {
        case 1:
            std::cin >> x >> y >> k;

            add(x, k);
            add(y + 1, -k);
            break;
        case 2:
            std::cin >> x;

            std::cout << sum(x) << "\n";
            break;
        default:
            break;
        }
    }
}