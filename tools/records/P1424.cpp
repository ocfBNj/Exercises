#include <iostream>

int main() {
    int x;
    int n;
    int res = 0;

    std::cin >> x >> n;

    n += (x - 1);
    //假设从第一天开始
    res += (n / 7) * 5 * 250;
    if (n % 7 <= 5) {
        res += n % 7 * 250;
    } else {
        res += 5 * 250;
    }

    if (x <= 5) {
        res -= (x - 1) * 250;
    } else {
        res -= 5 * 250;
    }

    std::cout << res << std::endl;
}