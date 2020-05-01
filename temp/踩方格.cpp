#include <iostream>
#include <tuple>
#include <vector>

int map[50][50];
char used[50][50];
std::vector<std::tuple<int, int>> path;
int n;

int resolve(int i, int j, int n) {
    if (used[i][j]) return 0;
    if (!n) {
        for (const auto& [i_, j_] : path) {
            std::cout << "(" << i_ << ", " << j_ << "); ";
        }
        std::cout << "(" << i << ", " << j << ")\n";
        return 1;
    }

    used[i][j] = 1;
    path.push_back({i, j});
    n--;
    int ret = resolve(i + 1, j, n) + resolve(i, j - 1, n) + resolve(i, j + 1, n);
    path.pop_back();
    used[i][j] = 0;

    return ret;
}

int main() {
    std::cin >> n;
    std::cout << resolve(0, 25, n) << "\n";
}
