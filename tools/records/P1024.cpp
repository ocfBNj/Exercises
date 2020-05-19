#include <iostream>
#include <cmath>
#include <iomanip>

double a, b, c, d;
double x1, x2, x3;

inline double cacl(double x) {
	return a * x * x * x + b * x * x + c * x + d;
}

inline bool isOK(double res) {
	return std::abs(res) <= 1e-2;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(2);

	std::cin >> a >> b >> c >> d;
	// (3*a)*x*x + (2*b)*x + c;
	x1 = ((-2 * b) + std::sqrt((2 * b) * (2 * b) - 4 * (3 * a) * c)) / (2 * (3 * a));
	x3 = ((-2 * b) - std::sqrt((2 * b) * (2 * b) - 4 * (3 * a) * c)) / (2 * (3 * a));

	bool isD = cacl(x1) > cacl(x3); // 递减
	// 求中间的根
	while (true) {
		x2 = (x1 + x3) / 2;
		double temp = cacl(x2);
		if (isOK(temp)) break;
		else if (temp > 0) {
			if (isD) {
				x1 = x2;
			} else {
				x3 = x2;
			}
		} else {
			if (isD) {
				x3 = x2;
			} else {
				x1 = x2;
			}
		}
	}

	double min = -100;
	double max = 100;

	// 求x1
	max = x2;
	while (true) {
		x1 = (max + min) / 2;
		double temp = cacl(x1);
		if (isOK(temp)) break;
		else if (temp > 0) {
			if (isD) {
				min = x1;
			} else {
				max = x1;
			}
		} else {
			if (isD) {
				max = x1;
			} else {
				min = x1;
			}
		}
	}

	// ---- 
	min = -100;
	max = 100;
	// ---- 

	// 求x3
	min = x2;
	while (true) {
		x3 = (max + min) / 2;
		double temp = cacl(x3);
		if (isOK(temp)) break;
		else if (temp > 0) {
			if (isD) {
				min = x3;
			} else {
				max = x3;
			}
		} else {
			if (isD) {
				max = x3;
			} else {
				min = x3;
			}
		}
	}

	std::cout << x1 << " " << x2 << " " << x3 << "\n";
}
