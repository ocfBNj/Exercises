#include <iostream>
#include <queue>

#define SIZE 10005

int counts[SIZE];

int main() {
	int n;
	int res = 0;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> counts[i];
	}

	std::priority_queue<int, std::vector<int>, std::greater<int>> que(counts, counts + n);
	while (que.size() > 1) {
		int a, b;
		a = que.top();
		que.pop();
		b = que.top();
		que.pop();

		res += a + b;
		que.push(a + b);
	}

	std::cout << res << std::endl;
}