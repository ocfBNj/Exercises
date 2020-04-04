#include <iostream>

int n;
double p;
double a[100001];
double b[100001];

// p*t+b[i] - a[i]*t = 0 ==> t
// t*(p - a[i]) + b[i] = 0
// t = -b[i] / (p - a[i])
// p*x + b[i] - a[i]*t >= 0
// p*x >= a[i]*t - b[i]
// x >= (a[i]*t - b[i]) / (double)p
inline bool isOK(double t) {
	double countT = 0; // 充电电量
	for (int i = 0; i < n; i++)  {
		if (a[i]*t <= b[i]) continue; // 不需要充电 
		countT += a[i]*t - b[i];
		// std::cout << "countT: " << countT << "\n\n";
		if (countT > t*p) return false;
	}
	
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cout.setf(std::ios_base::fixed);
	std::cout.precision(10);
	
	std::cin >> n >> p;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i] >> b[i];
		sum += a[i];
	}
	
	if (sum <= p)
		std::cout << -1 << "\n";
	else {
		double min = 0;
		double max = 1e10;
		double t;
		while (max - min > 1e-6) {
			t = (min + max) / 2;
			// std::cout << "t: " << t << "\n";
			if (isOK(t)) {
				min = t;
			} else {
				max = t;
			}
		}
		
		std::cout << min << "\n";
	}
		
}

