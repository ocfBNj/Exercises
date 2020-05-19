#include <iostream>
#include <limits>

#define SIZE 100005

int arr[SIZE];

int n;
int k;

int main() {
	int max = std::numeric_limits<int>::min();
	std::cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		std::cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	for (int i = k; i <= n; i++) {
		if (arr[i] - arr[i - k] > max) {
			max = arr[i] - arr[i - k];
		}
	}

	std::cout << max << std::endl;


	return 0;
}
