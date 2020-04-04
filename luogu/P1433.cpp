#include <iostream>
#include <cmath>
#include <limits>

struct Pos {
	double x;
	double y;
};

inline double distance(const Pos& src, const Pos& des) {
	return std::sqrt((src.x - des.x) * (src.x - des.x) 
		+ (src.y - des.y) * (src.y - des.y));
}

Pos arr[17];
bool used[17];
int n;
double res = std::numeric_limits<double>::max();

void resolve(int curPosI, int count, double dis) {
	if (count == n) {
		if (dis < res) res = dis;
	} else {
		for (int i = 1; i <= n; i++) {
			if (!used[i]) {
				used[i] = true;

				// 走
				double temp = dis + distance(arr[curPosI], arr[i]);
				if (temp > res) {
					used[i] = false;
					return;
				}
				resolve(i, count + 1, temp);

				used[i] = false;
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> n;
	Pos start = { 0, 0 };
	arr[0] = start;

	for (int i = 1; i <= n; i++) {
		std::cin >> arr[i].x >> arr[i].y;
	}

	resolve(0, 0, 0);
	std::cout.setf(std::ios_base::fixed);
	std::cout.precision(2);
	std::cout << res << "\n";
}
