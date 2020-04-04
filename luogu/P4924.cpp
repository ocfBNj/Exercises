#include <iostream>

int map[505][505];
int right_left[2][505];
int bottom_up[2][505];
int n, m;

void rotate(int x, int y, int r, int dir) {
    if (r == 0) return;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 * r + 1; j++) {
            int c = (i == 0 ? 1 : -1);
            right_left[i][j] = map[x - r + j][y + c*r];
            bottom_up[i][j] = map[x + c*r][y - r + j];
        }
    }

    if (dir == 0) {
        for (int i = 0; i < 2*r + 1; i++)
            map[x - r][y - r + i] = right_left[1][2*r - i];
        for (int i = 0; i < 2*r + 1; i++)
            map[x - r + i][y + r] = bottom_up[1][i];
        for (int i = 0; i < 2*r + 1; i++)
            map[x + r][y + r - i] = right_left[0][i];
        for (int i = 0; i < 2*r + 1; i++)
            map[x + r - i][y - r] = bottom_up[0][2*r - i];
    } else {
        for (int i = 0; i < 2*r + 1; i++)
            map[x - r][y - r + i] = right_left[0][i];
        for (int i = 0; i < 2*r + 1; i++)
            map[x - r + i][y + r] = bottom_up[0][2*r - i];
        for (int i = 0; i < 2*r + 1; i++)
            map[x + r][y + r - i] = right_left[1][2*r - i];
        for (int i = 0; i < 2*r + 1; i++)
            map[x + r - i][y - r] = bottom_up[1][i];
    }
        
    rotate(x, y, r - 1, dir);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin >> n >> m;
    int temp = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            map[i][j] = temp++;
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y, r, z;
        std::cin >> x >> y >> r >> z;

        rotate(x, y, r, z);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << map[i][j] << " ";
        }
        std::cout << "\n";
    }
}
