#include <iostream>

int main()
{
	long long n;
	long long a, b, c, d;
	std::cin >> n >> a >> b >> c >> d;
	long long res = n / a + n / b + n / c + n / d - n / a / b - n / a / c - n / a / d - n / b / c - n / b / d - n / c / d
		- n / a / b / c / d + n / a / b / c + n / a / b / d + n / a / c / d + n / b / c / d;
	std::cout << res << std::endl;
}
