#include <iostream>

#define SIZE 2000004

int num[SIZE];

int main()
{
	int n, m, temp;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		if (temp >= 0)
			num[temp]++;
		else
			num[SIZE + temp]++;
	}

	for (int i = 0; i < m; i++) {
		std::cin >> temp;
		if (temp >= 0)
			std::cout << num[temp] << std::endl;
		else
			std::cout << num[SIZE + temp] << std::endl;
	}
	return 0;
}