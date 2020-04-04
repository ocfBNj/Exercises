#include <iostream>
#include <algorithm>
#include <limits>

long long arr[1000001];
long long n, m;

// 返回值大于等于0表示可以完成任务，此时尝试更高的h 
long long isOK(long long h) {
	long long sum = 0;
	for (long long i = 0; i < n; i++) {
		if (arr[i] - h > 0) sum += arr[i] - h;
		if (sum - m >= 0) return 1; 
	}
	
	return -1;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	
	std::cin >> n >> m;
	long long max = std::numeric_limits<long long>::min();
	long long min = std::numeric_limits<long long>::max();
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
	}
	
	int h;
	int temp;
	int res = 0;
	while (min <= max) {
		h = (max + min) / 2;
		
		temp = isOK(h);
		// std::cout << h << " " << temp << "\n";
		if (temp > 0) {
			res = h;
			min = h + 1;
		} else {
			max = h - 1;
		}
	}
	
	std::cout << res << "\n";
}

