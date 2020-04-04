#include <iostream>
#include <cmath>

double ori, money, month;

inline double cacl(double rate) {
	rate /= 100;
	return money - ori * rate * (std::pow(1 + rate, month) 
		/ (std::pow(1 + rate, month) - 1));
}

bool isOK(double re) {
	return std::abs(re) < 1e-4; 
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cout.setf(std::ios_base::fixed);
	std::cout.precision(1);
	
	
	std::cin >> ori >> money >> month;
	double max = 1000;
	double min = 0;
	double mid;
	while (min <= max) {
		mid = (max + min) / 2;
		double ret = cacl(mid);
		if (isOK(ret)) {
			std::cout << mid << "\n";
			break;
		} else if (ret > 0) {
			min = mid;
		} else {
			max = mid;
		}
	}
	
}

