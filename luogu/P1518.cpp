#include <iostream>

char map[10][10];
int fI, fJ;
int fDir[2] = {-1, 0};

int cI, cJ;
int cDir[2] = {-1, 0};

int res;

inline bool isNeedAdjust(int i, int j) {
    return i < 0 || j < 0 || i >= 10 || j >= 10 || map[i][j] == '*';
}

inline void adjust(int& i, int& j) {
    if (i == 1 && j == 0) {
        i = 0;
        j = -1;
    } else if (i == -1 && j == 0) {
        i = 0;
        j = 1;
    } else if (i == 0 && j == -1) {
        i = -1;
        j = 0;
    } else {
        i = 1;
        j = 0;
    }
}

bool resolve() {
    while (true) {
        if (fI == cI && fJ == cJ) return true;
        if (res > 10000) break;

        res += 1;

        if (isNeedAdjust(fI + fDir[0], fJ + fDir[1])) {
            adjust(fDir[0], fDir[1]);
        } else {
            fI += fDir[0];
            fJ += fDir[1];
        }

        if (isNeedAdjust(cI + cDir[0], cJ + cDir[1])) {
            adjust(cDir[0], cDir[1]);
        } else {
            cI += cDir[0];
            cJ += cDir[1];
        }
    }
    
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cin >> map[i][j];
            if (map[i][j] == 'F') {
                fI = i;
                fJ = j;
            } else if (map[i][j] == 'C') {
                cI = i;
                cJ = j;
            }
        }
    }
    
    if (resolve())
        std::cout << res << "\n";
    else
        std::cout << 0 << "\n";
    
}
