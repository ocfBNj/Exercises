#include <iostream>
#include <algorithm>

int T, M;
int t[100];
int value[100];
int saved[101][1001];

int resolve(int i, int time) {
    if (i == 0 || time == 0) return 0;
    if (saved[i][time]) return saved[i][time];

    saved[i - 1][time] = resolve(i - 1, time);
    if (time >= t[i - 1]) {
        saved[i - 1][time - t[i - 1]] = resolve(i - 1, time - t[i - 1]);
        saved[i][time] = std::max(saved[i - 1][time],
                                  saved[i - 1][time - t[i - 1]] + value[i - 1]);
    } else {
        saved[i][time] = saved[i - 1][time];
    }

    return saved[i][time];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> T >> M;
    for (int i = 0; i < M; i++) {
        std::cin >> t[i] >> value[i];
    }

    std::cout << resolve(M, T) << "\n";
}
