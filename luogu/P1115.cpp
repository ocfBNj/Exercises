#include <iostream>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    long long res = std::numeric_limits<long long>::min();
    long long sum = 0;
    bool hasZero = false;
    int n;
    int num;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        if (!num) hasZero = true;
        sum += num;

        if (sum != 0 && sum > res) res = sum;
        if (sum < 0) sum = 0;
    }

    if (hasZero) res = 0 > res ? 0 : res;
    std::cout << res << "\n";
}
