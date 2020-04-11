#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <tuple>

int n;
int arr[20];
int dp[20];
std::unordered_set<int> connect[20];

std::tuple<std::string, int> resolve(int i, const std::string& str, int value) {
    int max = value;
    std::string string = str;
    for (auto it = connect[i].begin(); it != connect[i].end(); ++it) {
        int j = *it;
        const auto& [str_, value_] = resolve(
            j, str + std::string(" ").append(std::to_string(j + 1)), arr[j] + value);

        if (value_ > max) {
            max = value_;
            string = str_;
        }
    }

    return {string, max};
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp;
            std::cin >> temp;
            if (temp) connect[i].insert(j);
        }
    }

    int max = 0;
    std::string string;
    for (int i = 0; i < n; i++) {
        const auto& [str, value] = resolve(i, std::to_string(i + 1), arr[i]);
        if (value > max) {
            max = value;
            string = str;
        }
    }
    
    std::cout << string << "\n" << max << "\n";
}
