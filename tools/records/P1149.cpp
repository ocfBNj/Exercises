#include <iostream>
#include <vector>
#include <string>
#include <map>

int map[10] = { 6,2,5,5,4,5,6,3,7,6 };

int countNum(int num) {
	int n = 0;

	if (num == 0) return map[0];

	while (num) {
		n += map[num % 10];
		num /= 10;
	}

	return n;
}

int main() {
	int n;
	std::cin >> n;
	n -= 4;
	int count = 0;

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			if (countNum(i) + countNum(j) + countNum(i + j) == n)
				count++;
		}
	}

	std::cout << count << std::endl;

}