#include <iostream>
#include <algorithm>
#include <numeric>

int s[4];
int work[20];
int dp[2501];
int times;
int total;
int left, right;

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin >> s[0] >> s[1] >> s[2] >> s[3];
    for (int i = 0; i < 4; i++) {
        left = right = 0;

        total = 0;
        for (int j = 0; j < s[i]; j++) {
            std::cin >> work[j];
            total += work[j];
        }

        for (int j = 0; j < s[i]; j++) {
            for (int k = total / 2; k >= work[j]; k--) {
                dp[k] = std::max(dp[k], dp[k - work[j]] + work[j]);
            }
        }

        times += total - dp[total / 2];
        for (int j = 1; j <= total / 2; j++) {
            dp[j] = 0;
        }
    }

    std::cout << times << '\n';
}
