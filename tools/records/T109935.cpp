#include <iostream>

int main()
{
	int m, n, a, b;
	int f;
	std::cin >> m >> n >> a >> b;

	for (f = 1; f < 100; f++) {
		if ((n - f * a) % b == 0) {
			if (f * (2 * a) + (n - f * a) / b * (4 * b) == m) {
				break;
			}
		}
	}

	if (f >= 100) {
		std::cout << -1 << std::endl;
	} else {
		std::cout << f << " " << (n - f * a) / b << std::endl;
	}
}