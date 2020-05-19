#include <iostream>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    long long res = std::numeric_limits<long long>::min();
    long long sum = 0;
    int n;
    int num;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> num;
        sum += num;
        
        if (sum != 0 && sum > res) res = sum;
        if (sum < 0) sum = 0;
    }

    std::cout << res << "\n";
}
