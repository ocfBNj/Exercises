#include <iostream>
#include <algorithm>

int l, n, k;
int dis[100005];

inline bool isOK(int len) {
	int count = 0;
	int curDis = 0;
	int* pNext = dis + 1;
	while (curDis < l && pNext != dis + n) {
		if (*pNext - curDis <= len) {
			// 不用增加 
			curDis = *pNext++;
		} else {
			// 增加一块 
			count++;
			if (count > k) return false;
			curDis += len;
		}
		
	}
	
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	
	std::cin >> l >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> dis[i];
	}
	
	int max = l;
	int min = 1;
	int len;
	int res = -1;
	while (min <= max)  {
		len = (min + max) / 2;
		if (isOK(len)) {
			res = len;
			max = len - 1;
		} else {
			min = len + 1;
		}
	}
	
	std::cout << res << '\n';
}

