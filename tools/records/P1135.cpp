#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_set>

int func(const std::vector<int>& arr, int begin, int end, int n) {
	std::queue<std::pair<int, int>> que;
	std::unordered_set<int> set;
	que.push({ begin, -1 });

	while (!que.empty()) {
		std::pair<int, int> cur = que.front();
		que.pop();

		if (cur.first >= 0 && cur.first <= n && set.find(cur.first) == set.end()) {
			cur.second++;
			if (cur.first == end) return cur.second;

			que.push({ cur.first + arr[cur.first], cur.second });
			que.push({ cur.first - arr[cur.first], cur.second });

			set.insert(cur.first);
		}

	}

	return -1;
}


int main() {
	int n;
	int cur;
	int end;

	std::cin >> n >> cur >> end;
	
	std::vector<int> arr(n);
	for (int i = 0, num; i < arr.size(); i++) {
		std::cin >> num;
		arr[i] = num;
	}

	std::cout << func(arr, cur - 1, end - 1, n - 1) << std::endl;
}