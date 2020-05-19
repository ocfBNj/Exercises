#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <tuple>

using Map = std::vector<std::vector<int>>;
using Point = std::tuple<int, int, int>;

void bfs(Map& map, int i, int j) {
	std::queue<Point> que;
	que.push({ i, j, -1 });

	while (!que.empty()) {
		Point point = que.front();
		que.pop();
		int first = std::get<0>(point);
		int second = std::get<1>(point);
		int value = std::get<2>(point);
		if (first >= 0 && first < map.size() &&
			second >= 0 && second < map[0].size() &&
			map[first][second] == -1) {
			map[first][second] = ++value;

			que.push({ first - 1, second + 2, value });
			que.push({ first + 1, second + 2, value });
			que.push({ first - 1, second - 2, value });
			que.push({ first + 1, second - 2, value });
			que.push({ first - 2, second + 1, value });
			que.push({ first - 2, second - 1, value });
			que.push({ first + 2, second + 1, value });
			que.push({ first + 2, second - 1, value });

		}

	}
}

int main() {
	int row;
	int col;

	int beginRow;
	int beginCOl;
	std::cin >> row >> col;
	std::cin >> beginRow >> beginCOl;

	Map map(row, std::vector<int>(col, -1));
	bfs(map, beginRow - 1, beginCOl - 1);

	for (auto& arr : map) {
		for (int num : arr) {
			std::cout << std::left << std::setw(5) << num;
		}
		std::cout << std::endl;
	}

}