#include <iostream>

int n, k;
int arr[100001];
int min, max;

bool test(int len) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret += arr[i] / len;
		if (ret >= k) return true;
	}
	
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
		if (arr[i] > max)  max = arr[i];
	}
	
	int res = 0;
	int len;
	while (min <= max) {
		len = (max + min) / 2;
		if (!len) {
			if (test(1)) res = 1;
			break;
		}
		if (test(len)) {
			res = len;
			min = len + 1;
		} else {
			max = len - 1;
		}
	}
	
	std::cout << res << "\n";
	
}
