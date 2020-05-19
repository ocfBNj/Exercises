#include <iostream>

#define SIZE 3000005

int buf[SIZE];

int main()
{
	int n, k;
	int res = 0;
	std::cin >> n >> k;

	for (int i = 0; i < n; i++) {
		std::cin >> buf[i];
		res ^= buf[i];
	}

	if (k == 1) {
		std::cout << res << std::endl;
	} else {
		int a = 0;
		int b = 0;
		int index = 1;

		for (int i = 0; i < 32; i++) {
			index = 1 << i;
			if (res & index) {
				break;
			}
		}

		for (int i = 0; i < n; i++) {
			if (buf[i] & index) {
				a ^= buf[i];
			} else {
				b ^= buf[i];
			}
		}

		if (a > b) {
			std::swap(a, b);
		}

		std::cout << a << " " << b << std::endl;
	}

}