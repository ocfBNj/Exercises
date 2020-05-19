#include<iostream>

int main() {
	int a, p;
	while(std::cin >> a >> p) {
		std::cout << (p - (a % p)) % p << std::endl;
	}
	return 0;
}
