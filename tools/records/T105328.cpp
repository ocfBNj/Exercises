#include <iostream>
#include <string>

int main() {
	std::string n;
	std::cin >> n;
	
	if (n[n.size() - 1] % 2 == 0) {
		std::cout << "N0";
	} else {
		std::cout << "B0B0 ZHEN SHUAI!";
	}
}