#include <iostream>
#include <cmath>
#include <climits>

int main() {
    int res = INT_MAX;
    int count;
    int money;
    int desCount;

    std::cin >> desCount;

    for (int i = 0; i < 3; i++) {
        std::cin >> count >> money;
        int temp = std::ceil((double) desCount / count) * money;
        if (temp < res) res = temp;
    }

    std::cout << res << std::endl;
}