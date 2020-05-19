#include <iostream>
#include <vector>
#include <set>
#include <cmath>

#define SIZE 100005

int primers[SIZE]{};
int disjoint_set[SIZE]{};
int value[SIZE]{};
int a, b, p;
int count = 0;

int find_set(int num) {
	if (disjoint_set[num] != 0) {
		num = find_set(disjoint_set[num]);
	}
	return num;
}

void union_set(int lhs, int rhs) {
	if (lhs == rhs) return;

	if (lhs >= a && lhs <= b &&
		rhs >= a && rhs <= b) {
		count--;
	}

	if (value[lhs] > value[rhs]) {
		disjoint_set[rhs] = lhs;
	} else {
		if (value[lhs] == value[rhs]) value[rhs]++; //权重相等情况下连到右边
		disjoint_set[lhs] = rhs;
	}
}

int main() {
	std::cin >> a >> b >> p;
	count = b - a + 1;

	//求素数
	for (int i = 2; i <= b; i++) {
		if (!primers[i]) {
			for (int j = i, n = 2; j * n <= b; n++) {
				if (i >= p && j * n >= a && j * n <= b) {
					union_set(find_set(i), find_set(j * n));
				}
				primers[j * n] = 1;
			}
		}
	}

	std::cout << count << std::endl;

	return 0;
}

