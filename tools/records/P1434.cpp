#include <iostream>
#include <algorithm>

int row;
int column;

int map[100][100];
int saved[100][100];

int res;

void resolve(int i, int j, int count, int old_value) {
    if (i >= 0 && i < row && j >= 0 && j < column && map[i][j] > old_value) {
        count++;
        if (count <= saved[i][j]) return;

        saved[i][j] = count;
        resolve(i + 1, j, count, map[i][j]);
        resolve(i - 1, j, count, map[i][j]);
        resolve(i, j + 1, count, map[i][j]);
        resolve(i, j - 1, count, map[i][j]);

        if (saved[i][j] > res) res = saved[i][j];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> row >> column;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            std::cin >> map[i][j];
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            resolve(i, j, 0, -1);
        }
    }
    
    std::cout << res << "\n";
}
