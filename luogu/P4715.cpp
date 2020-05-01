#include <iostream>
#include <algorithm>

struct Country {
    int value;
    int id;
};

bool operator<(const Country& left, const Country& right) {
    return left.value < right.value;
}

Country arr[128];

int main() {
    unsigned n, count;
    std::cin >> n;
    count = 1 << n;
    for (unsigned i = 0; i < count; i++) {
        std::cin >> arr[i].value;
        arr[i].id = i + 1;
    }

    while (count != 2) {
        int index = 0;
        for (unsigned i = 0; i < count; i += 2) {
            arr[index++] = std::max(arr[i], arr[i + 1]);
        }

        count >>= 1;
    }

    std::cout << std::min(arr[0], arr[1]).id << "\n";
}