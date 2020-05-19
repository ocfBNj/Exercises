#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::vector<int> numbers;
	int number;
	int n, q;
	int count = 0;
	while (true) {
		std::cin >> n >> q;
		if (!n && !q) return 0;
		count++;
		std::cout << "CASE# " << count << ":\n";
		for (int i = 0; i < n; i++) {
			std::cin >> number;
			numbers.push_back(number);
		}

		std::sort(numbers.begin(), numbers.end());
		for (int i = 0; i < q; i++) {
			std::cin >> number;
			int len = numbers.size();
			int j = 0;
			for (; j < len; j++) {
				if (numbers[j] == number) {
					std::cout << number << " found at " << j + 1 << std::endl;
					break;
				}
			}

			if (j == len) {
				std::cout << number << " not found" << std::endl;
			}
		}
		numbers.clear();
	}
}