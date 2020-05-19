#include <iostream>
#include <algorithm>
#include <limits>

int l, n, m;
int dis[50005];
int min, max;
int res = std::numeric_limits<int>::max();

bool isOK(int len) {
	int count = 1; // 移走的石头
	int curDis = 0;
	int* pCur = dis;
	while (curDis < l) {
		curDis += len; // 假设可以行走 
		int* pNext = std::lower_bound(pCur, dis + n, curDis);
		count += (pNext - pCur) - 1;
		if (count > m) return false;
		
		curDis = *pNext;
		pCur = pNext;
		
		// std::cout << "len: " << len << " curDis: " << curDis << " count: " << count<< "\n";
		// Sleep(2000);
	}
	
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin >> l >> n >> m;
	
	if (n == 0) res = l;
	
	for (int i = 0; i < n; i++) {
		std::cin >> dis[i];
		if (i > 0) {
			int temp = dis[i] - dis[i - 1];
			if (temp < res) res = temp; // 找到最短跳跃距离 
		}
	}
	dis[n++] = std::numeric_limits<int>::max() - 1000000000;
	int temp = dis[n - 1] - dis[n - 2];
	if (temp < res) res = temp;
	
	min = res;
	max = l;
	
	int len;
	while (min <= max) {
		len = (min + max) / 2;
		if (!len) break;
		if (isOK(len)) {
			res = len;
			min = len + 1;
		} else {
			max = len - 1;
		}
	}
	
	std::cout << res << "\n";
}
