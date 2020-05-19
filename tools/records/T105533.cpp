#include <iostream>

int main() {
	long long money;
	long long i;
	long long last;
	long long count = 0;

	while (std::cin >> money) {
		last = money;
		count = 0;
		if (money <= 0) {
			std::cout << 0 << ' ' << 0 << std::endl;
		} else {
			while (true) {
				for (i = 1; i < last;) {
					i *= 2;
				}
				count++;
				if (i == last) {
					break;
				} else {
					last -= i / 2;
				}
			}
			std::cout << count << ' ' << money << std::endl;
		}
	}
}