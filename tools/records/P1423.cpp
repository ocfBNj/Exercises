#include <iostream>
#include <cmath>

int main() {
    double len;
    std::cin >> len;

    int count = 0;
    double countLen = 0;

    while (countLen < len) {
        countLen += 2 * std::pow(0.98, count++);
    }

    std::cout << count << std::endl;
}