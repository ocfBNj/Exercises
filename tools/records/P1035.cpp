#include <iostream>

int main() {
    int n = 0;
    int k = 0;
    double sum = 0;

    std::cin >> k;
    do {
        n++;
        sum += 1.0 / n;

    } while (sum <= k);

    std::cout << n << std::endl;
}