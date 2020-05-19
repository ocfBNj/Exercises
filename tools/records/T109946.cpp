#include <iostream>
#include <algorithm>

#define SIZE 1005

int trees[SIZE];

int main()
{
	int n, q;
	std::cin >> n >> q;
	for (int i = 1, heigh; i <= n; i++) {
		std::cin >> heigh;
		trees[i] = heigh;
	}

	for (int i = 1, l, r; i <= q; i++) {
		std::cin >> l >> r;
		auto max = std::max_element(&trees[l], &trees[r + 1]);
		auto min = std::min_element(&trees[l], &trees[r + 1]);

		std::iter_swap(max, min);
	}

	for (int i = 1; i <= n; i++) {
		std::cout << trees[i] << " ";
	}

	return 0;
}