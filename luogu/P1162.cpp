#include <iostream>
#include <queue>
#include <set>

bool bfs(int** arr, int i, int j, int n) {
	std::queue<std::pair<int, int>> que;
	std::set<std::pair<int, int>> _set;
	que.push({ i, j });

	while (!que.empty()) {
		std::pair<int, int> cur = que.front();
		que.pop();

		if (arr[cur.first][cur.second] == 0) {
			if (_set.find({ cur.first, cur.second }) != _set.end()) continue;

			_set.insert({ cur.first, cur.second });

			if (cur.first - 1 < 0 || cur.first + 1 >= n ||
				cur.second - 1 < 0 || cur.second + 1 >= n)
				return false;

			que.push({ cur.first - 1, cur.second });
			que.push({ cur.first + 1, cur.second });
			que.push({ cur.first, cur.second - 1 });
			que.push({ cur.first , cur.second + 1 });
		}
	}

	return true;
}

void print(int** arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << (int)arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	int n;
	std::cin >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			std::cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				if (bfs(arr, i, j, n))
					arr[i][j] = 2;
			}

		}
	}

	print(arr, n);

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}