#include <iostream>
#include <iterator>
#include <algorithm>
#include <cmath>

int scores[100005];

int main() {
	std::ios_base::sync_with_stdio(false);
	int m, n;
	std::cin >> m >> n;
	
	for (int i = 0; i < m; i++) {
		std::cin >> scores[i];
	}
	
	std::sort(scores, scores + m);
	long long res = 0;
	
	int evalute;
	int min;
	for (int i = 0; i < n; i++) {
		std::cin >> evalute;
		int* p = std::lower_bound(scores, scores + m, evalute);
		if (std::distance(scores, p) > 0) {
			min = std::min(std::abs(evalute - *p), std::abs(evalute - *(p - 1)));
		} else if(p == scores + m) {
			min = std::abs(evalute - (*p - 1));
		} else {
			min = std::abs(evalute - *p);
		}
		
		res += min;
	}
	
	std::cout << res << "\n";
}

