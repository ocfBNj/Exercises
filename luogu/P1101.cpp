#include <iostream>
#include <string>
#include <algorithm>

std::string lines[101];
std::string res[101];
const std::string des = "yizhong";
int n;

void resolve(int count, int i, int j, int x, int y, const std::string& str) {
    if (count < 7 && i >= 0 && i < n && j >= 0 && j < n && lines[i][j] == des[count]) {
        const std::string temp = str + std::string(1, des[count]);
        if (temp == des) {
            int p = 7;
            // 检查
            int tempI = i;
            int tempJ = j;
            while (p > 0 && tempI >=0 && tempJ >= 0 && tempI < n && tempJ < n) {
                if (lines[tempI][tempJ] != des[--p]) break;
                tempI -= x;
                tempJ -= y;
            }
            if (p > 0) return;
            p = 7;
            while (p > 0) {
                res[i][j] = des[--p];
                i -= x;
                j -= y;
            }
            return;
        }
        resolve(count + 1, i + 1, j, 1, 0, temp);
        resolve(count + 1, i - 1, j, -1, 0, temp);
        resolve(count + 1, i, j + 1, 0, 1, temp);
        resolve(count + 1, i, j - 1, 0, -1, temp);
        resolve(count + 1, i + 1, j + 1, 1, 1, temp);
        resolve(count + 1, i + 1, j - 1, 1, -1, temp);
        resolve(count + 1, i - 1, j + 1, -1, 1, temp);
        resolve(count + 1, i - 1, j - 1, -1, -1, temp);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> lines[i];
        res[i].assign(n, '*');
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resolve(0, i, j, 0, 0, "");
        }
    }

    // std::cout << '\n';
    for (int i = 0; i < n; i++) {
        std::cout << res[i] << "\n";
    }
}
