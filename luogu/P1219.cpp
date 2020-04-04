#include <iostream>
#include <cmath>
#include <cstring>

char map[14];
int n;
int count = 0;

// 1, 1
// 2, 2
void resolve(int curN) {
	if (curN == n + 1) {
		if (++count <= 3) {
			for (int i = 1; i <= n; i++) {
				std::cout << (int)map[i] << " ";
			}
			std::cout << "\n";
		}
	} else {
		for (int i = 1; i <= n; i++)  {
			bool isOK = true;
			for (int j = 1; j < curN; j++) {
				if (i == map[j] || std::abs(curN - j) == std::abs(i - map[j])) {
					isOK = false;
					break;
				}
			}
			
			if (isOK) {
				map[curN] = i;
				resolve(curN + 1) ;
			}
			
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> n;
	resolve(1);
	std::cout << count << "\n";
}

