#include <iostream>
#include <algorithm>
#include <climits>

int numbers[10005];
int cur;

int main() {
    std::ios_base::sync_with_stdio(false);
    numbers[0] = std::numeric_limits<int>::min();

    int n;
    int number;
    int res = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> number;
        if (number > numbers[cur]) {
            numbers[++cur] = number;
        } else {
            *std::lower_bound(numbers + 1, numbers + 1 + cur, number) = number;
            res++;
        }
    }

    std::cout << res << '\n';
}
