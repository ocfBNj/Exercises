#include <iostream>
#include <algorithm>

int n;
int a, b, g, h;
int x, y;

struct Obj {
	int id;
	int a, b;
	int x, y;	
} arr[10005];

bool operator<(const Obj& lhs, const Obj& rhs) {
	return lhs.id < rhs.id;
}

bool pred(const Obj& lhs) {
	if (lhs.a > x || lhs.a + lhs.x < x || lhs.b > y || lhs.b + lhs.y < y) {
		return true;
	}
	
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> n;
	
	for (int i = 0; i != n; i++) {
		std::cin >> a >> b >> g >> h;
		arr[i + 1].id = i + 1;
		arr[i + 1].a = a;
		arr[i + 1].b = b;
		arr[i + 1].x = g;
		arr[i + 1].y = h;
	}
	
	std::cin >> x >> y;
	
	Obj* end = std::remove_if(arr + 1, arr + 1 + n, pred);
	n = end - (arr + 1);
	std::sort(arr + 1, end);
	Obj& lhs = arr[n];

	if (lhs.a > x || lhs.a + lhs.x < x || lhs.b > y || lhs.b + lhs.y < y) {
		std::cout << "-1\n";
	} else {
		std::cout << lhs.id << "\n";
	}
}