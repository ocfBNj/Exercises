#include <iostream>
#include <algorithm>

int n, q;
int ns[100005];
int money;

// 找到小于value的最大值
int find(int left, int right, int value) {
	int ret = 0;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (ns[mid] <= value) {
			ret = ns[mid];
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return ret;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> n >> q;

	for (int i = 0; i != n; i++) {
		std::cin >> ns[i];
	}

	std::sort(ns, ns + n);
	for (int i = 0; i != q; i++) {
		std::cin >> money;
		int ret = find(0, n - 1, money);
		std::cout << money - ret << "\n";
	}
}