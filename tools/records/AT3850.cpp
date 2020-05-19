#include <iostream>
#include <cstring>

#define SIZE 100005

// 1为2017数
int numbers[SIZE];
int _2017[SIZE];

int main() {
	numbers[1] = 0;
	for (int i = 2; i < SIZE; i++) {
		numbers[i] = 1;
	}

	for (int i = 2; i < SIZE; i++) {
		if (numbers[i]) {
			for (int j = 2; j * i < SIZE; j++) {
				numbers[j * i] = 0;
			}
		}
	}

	// 求2017数
	memcpy(_2017, numbers, sizeof numbers);
	_2017[2] = 0;
	for (int i = 3; i < SIZE; i += 2) {
		if (numbers[i] && !numbers[(i + 1) / 2]) {
			_2017[i] = 0;
		}
	}

	for (int i = 2; i < SIZE; i++) {
		_2017[i] += _2017[i - 1];
	}


	int question;
	std::cin >> question;
	while (question--) {
		int left, right;
		std::cin >> left >> right;

		std::cout << _2017[right] - _2017[left - 1] << std::endl;
	}

	return 0;
}
