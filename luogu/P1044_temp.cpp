#include <iostream>
#include <algorithm>
#include <fstream>

long long res;

void resolve(int left, int mid, int right) {
    if (right == 0) {
        res++;
        return;
    }

    if (mid == 0) {
        resolve(left, mid + 1, right - 1);
    } else {
        resolve(left + 1, mid  - 1, right);
        resolve(left, mid + 1, right - 1);
    }
}

int main() {
    res = 0;
    resolve(0, 0, 1000);
    std::cout << res << std::endl;
}
