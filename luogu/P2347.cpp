#include <bitset>
#include <iostream>

std::bitset<1008> bits;
int map[6] = {1, 2, 3, 5, 10, 20};
int arr[6];

int resolve() {
    bits.set(0);

    for (int i = 0; i != 6; i++) {
        for (int j = 0; j != arr[i]; j++) {
            bits |= bits << map[i];
        }
    }

    return static_cast<int>(bits.count()) - 1;
}

int main() {
    for (int i = 0; i != 6; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Total=" << resolve() << "\n";
}