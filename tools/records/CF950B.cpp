#include <iostream>

#define SIZE 1000005

int M[SIZE];
int N[SIZE];

int main() {
	int m, n;
	std::cin >> m >> n;

	for (int i = 0; i < m; i++) {
		std::cin >> M[i];
		if (i > 0) {
			M[i] += M[i - 1];
		}
	}

	for (int i = 0; i < n; i++) {
		std::cin >> N[i];
		if (i > 0) {
			N[i] += N[i - 1];
		}
	}

	int res = 0;

	for (int j = 0, k = 0; j < m && k < n; ) {
		if (M[j] < N[k]) {
			j++;
		} else if (M[j] > N[k]) {
			k++;
		} else {
			j++;
			k++;
			res++;
		}
	}

	std::cout << res << std::endl;

	return 0;
}
