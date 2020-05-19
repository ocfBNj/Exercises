#include <iostream>
#include <cstring>

char hava[65537];

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		memset(hava, 0, sizeof hava);
		int n;
		int number;
		int result = 0;
		std::cin >> n >> number;

		hava[number] = 1;
		result += number;

		for (int i = 1; i < n; i++) {
			std::cin >> number;

			for (int j = 0; ; j++) {
				if (number - j >= 0 && hava[number - j]
					|| number + j <= 65536 && hava[number + j]) {
					result += j;
					break;
				}
			}

			hava[number] = 1;
		}

		std::cout << result << std::endl;
	}
}
