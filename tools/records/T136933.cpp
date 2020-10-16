#include <iostream>

int n;

int main() {
	std::cin >> n;
	int a = 0;
	int b = 1;

	for (int i = 0; i != n; i++) {
		int temp = b;
		b = (a + b) % 100;
		a = temp;
	}

	std::cout << b;
}
