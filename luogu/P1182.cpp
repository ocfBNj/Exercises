#include <iostream>

int arr[100005];
int n, m;
int min = 1;
int max = 1000000000;

bool isOK(int sum) {
	int group = 1;
	int curSum = 0;
	for (int i = 0; i < n; i++) {
		curSum += arr[i];
		if (curSum > sum) {
			// 分组
			if (++group > m)  return false;
			curSum = arr[i];
			if (curSum > sum) return false;
		}
		
	}
	
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	
	int mid;
	while (min <= max) {
		mid = (max + min) / 2;
		if (isOK(mid)) {
			max = mid - 1;
		} else {
			min = mid + 1;
		}
	}
	
	std::cout << max + 1 << "\n";
}

