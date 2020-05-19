#include <iostream>
#include <cmath>
#include <cstring>

char map[14]; // map[第n行] = 第n列 
int n;
int count = 0;

// 1, 1
// 2, 2
void reslove(int curN) {
	if (curN == n + 1) {
		if (++count <= 3) {
			for (int i = 1; i <= n; i++) {
				std::cout << (int)map[i] << " ";
			}
			std::cout << "\n";
		}
	} else {
		// 尝试每一列
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
				// 继续放下一行
				reslove(curN + 1) ;
			}
			
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> n;
	reslove(1);
	std::cout << count << "\n";
}
