#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <tuple>

int map[305][305];
bool used[305][305];
int m;
int res = -1;
std::queue<std::tuple<int, int, int>> q;

void resolve() {
	q.push(std::make_tuple(0, 0, 0));
	while (!q.empty()) {
		auto [i, j, curT] = q.front();
		q.pop();

		if (i >= 0 && i < 305 && j >= 0 && j < 305 && curT < map[i][j] && !used[i][j]) {
			used[i][j] = true;
			// std::cout << "curT: " << curT << " i: " << i << " j: " << j << " map[i][j]: " << map[i][j] << "\n";
			if (map[i][j] == 1001) {
				// 逃脱成功
				res = curT;
				return;
			}

			q.push(std::make_tuple(i + 1, j, curT + 1));
			q.push(std::make_tuple(i - 1, j, curT + 1));
			q.push(std::make_tuple(i, j + 1, curT + 1));
			q.push(std::make_tuple(i, j - 1, curT + 1));
		}
	}
}

inline void destory(int i, int j, int t) {
	if (t < map[i][j]) {
		map[i][j] = t;
	}
	if (i + 1 >= 0 && i + 1 < 305 && j >= 0 && j < 305 && t < map[i + 1][j]) {
		map[i + 1][j] = t;
	}
	if (i - 1 >= 0 && i - 1 < 305 && j >= 0 && j < 305 && t < map[i - 1][j]) {
		map[i - 1][j] = t;
	}
	if (i >= 0 && i < 305 && j + 1 >= 0 && j + 1 < 305 && t < map[i][j + 1]) {
		map[i][j + 1] = t;
	}
	if (i >= 0 && i < 305 && j - 1 >= 0 && j - 1 < 305 && t < map[i][j - 1]) {
		map[i][j - 1] = t;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> m;

	for (int i = 0; i < 305; i++) {
		for (int j = 0; j < 305; j++) {
			map[i][j] = 1001;
		}
	}

	int x, y, t;
	for (int i = 0; i < m; i++) {
		std::cin >> x >> y >> t;
		destory(x, y, t);
	}

	resolve();

	std::cout << res << "\n";
}
