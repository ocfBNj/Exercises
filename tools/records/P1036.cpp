#include <iostream>
#include <vector>
#include <cmath>

int count = 0;

bool isPrime(int num) {
	if (num == 1 || num == 2) return true;
	for (int i = 2; i <= std::sqrt(num); i++) {
		if (num % i == 0) return false;
	}

	return true;
}

void combin(int res, int k, const std::vector<int>& v) {
	if (k > 0) {
		for (int i = 0; i <= v.size() - k; i++) {
			combin(res + v[i], k - 1, std::vector<int>(v.begin() + i + 1, v.end()));
		}
	} else {
		if (isPrime(res)) count++;
	}
}

int main() {
	int n;
	int k;
	int num;
	std::vector<int> vec;

	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		vec.push_back(num);
	}

	combin(0, k, vec);
	std::cout << count << std::endl;
}