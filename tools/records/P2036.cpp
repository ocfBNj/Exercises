#include <iostream>
#include <cmath>
#include <algorithm>

std::pair<int, int> arr[10];
int n;
int res[2] = {1000000001, 1000000001};

void reslove(int i, int first, int second) {
    if (i == n) {
        if (int temp = std::abs(first - second); temp < std::max(res[0], res[1])) {
            *std::max_element(res, res + 2) = temp;
        }
        return;
    }

    reslove(i + 1, first, second);
    reslove(i + 1, first * arr[i].first, second + arr[i].second);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i].first >> arr[i].second;
    }

    reslove(0, 1, 0);
    if (res[0] != 1)
        std::cout << res[0] << "\n";
    else
        std::cout << res[1] << "\n";
}
