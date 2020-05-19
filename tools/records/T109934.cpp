#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main()
{
	int n = 0, d;
	double temp;
	double res = 0;
	int cur_count = 0;
	std::cin >> n >> d;
	std::vector<std::pair<int, double>> vec(n);
	

	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		vec[i].first = temp;
	}

	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		vec[i].second = temp;
	}

	std::sort(vec.begin(), vec.end(), [](auto& l, auto& r) {
		return l.second / (double)l.first > r.second / (double)r.first;
		});
	
	for (int i = 0; i < n; i++) {
		if (vec[i].first > d - cur_count) {
			res += (d - cur_count) * (vec[i].second / vec[i].first);
			break;
		}
		cur_count += vec[i].first;
		res += vec[i].second;
	}

	printf("%.1lf\n", res * 10);

	return 0;
}