#include <iostream>
#include <cctype>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>

int n, m;
char map[305][305];
std::pair<int, int> begin;
std::queue<std::tuple<int, int, int>> q;
std::unordered_map<char, std::pair<int, int>> table;
std::map<std::pair<int, int>, std::pair<int, int>> mapping;
std::set<std::pair<int, int>> used;
int res;

inline void reslove() {
    while (!q.empty()) {
        auto [i, j, t] = q.front();
        q.pop();

        if (i >= 0 && i < n && j >= 0 && j < m && map[i][j] != '#') {
            if (used.find({i, j}) != used.end()) continue;
            used.insert({i, j});

            // std::cout << "i: " << i << " j: " << j << " t: " << t << " map[i][j]" << map[i][j] << "\n";

            if (map[i][j] == '=') {
                res = t;
                return;
            }

            if (std::isalpha(map[i][j])) {
                auto [desI, desJ] = mapping[{i, j}];
                q.push({desI + 1, desJ, t + 1});
                q.push({desI - 1, desJ, t + 1});
                q.push({desI, desJ - 1, t + 1});
                q.push({desI, desJ + 1, t + 1});
            } else {
                q.push({i + 1, j, t + 1});
                q.push({i - 1, j, t + 1});
                q.push({i, j - 1, t + 1});
                q.push({i, j + 1, t + 1});
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> map[i][j];
            if (map[i][j] == '@') q.emplace(i, j, 0);
            if (std::isalpha(map[i][j])) {
                if (table.find(map[i][j]) == table.end()) {
                    table[map[i][j]] = {i, j};
                } else {
                    mapping[table[map[i][j]]] = {i, j};
                    mapping[{i, j}] = table[map[i][j]];
                }
            }
        }
    }

    reslove();

    std::cout << res << "\n";
}
