#include <iostream>

#define SIZE 50004

int disjoint_set[3 * SIZE];

int find_set(int n) {
	if (disjoint_set[n] != n) {
		n = find_set(disjoint_set[n]);
	}
	return n;
}

inline void union_set(int lp, int rp) {
	disjoint_set[lp] = rp;
}

int main() {
	int n, k;
	int oper, left, right;
	int res = 0;
	std::cin >> n >> k;

	//自环
	for (int j = 0; j < 3; j++) {
		for (int i = 1; i <= n; i++) {
			disjoint_set[i + j * SIZE] = i + j * SIZE;
		}
	}
	

	while (k--) {
		std::cin >> oper >> left >> right;
		if (left > n || right > n) {
			res++;
			continue;
		}

		if (oper == 1) {
			if (left == right) continue;
			if (find_set(left + SIZE) == find_set(right) || 
				find_set(left + 2 * SIZE) == find_set(right)) {
				res++;
				continue;
			}

			union_set(find_set(left), find_set(right));
			union_set(find_set(left + SIZE), find_set(right + SIZE));
			union_set(find_set(left + 2 * SIZE), find_set(right + 2 * SIZE));
		} else {
			if (left == right || find_set(left) == find_set(right) ||
				find_set(left + 2 * SIZE) == find_set(right)) {
				res++;
				continue;
			}

			union_set(find_set(left + 2 * SIZE), find_set(right + SIZE));
			union_set(find_set(left), find_set(right + 2 * SIZE));
			union_set(find_set(left + SIZE), find_set(right));
		}

	}

	std::cout << res << std::endl;
}