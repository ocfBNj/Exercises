#include <iostream>

long long arr[1000];

int main() {
	std::ios_base::sync_with_stdio(false);
	
	int n, m;
	int temp;
	
	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		std::cin >> temp;
		arr[temp - 1]++;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < arr[i]; j++) {
			std::cout << i + 1 << " ";
		}
	}
}
