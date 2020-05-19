#include <iostream>

#define SIZE 6

char map[SIZE][SIZE]; //起点为1、终点为2、障碍物为-1 
int res = 0;
int n, m, t; //n行m列 
int sX, sY, fX, fY;

void dfs(int i, int j) {
	if (i == fX && j == fY) {
		res++;
	} else if ( i < 1 || i > n || j < 1 || j > m || map[i][j] == -1 || map[i][j] == -2) {
		return;
	} else {
		map[i][j] = -2;
		
		dfs(i - 1, j);
		dfs(i + 1, j);
		dfs(i, j - 1);
		dfs(i, j + 1);
		
		map[i][j] = 0;
	}
}

int main() {
	std::cin >> n >> m >> t;

	std::cin >> sX >> sY >> fX >> fY;
	map[sX][sY] = 1;
	map[fX][fY] = 2;
	
	int i, j;
	while (t--) {
		std::cin >> i >> j;
		if (i == fX && j == fY) {
			std::cout << 0 << std::endl;
			return 0;
		}
		map[i][j] = -1;
	}
	
	dfs(sX, sY);
	std::cout << res << std::endl;
}