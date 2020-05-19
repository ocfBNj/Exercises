#include <iostream>
#include <algorithm>

int a;
int b[100005];
int mapping[100005];
int temp[100005];
int n;

inline int reslove() {
    int len = 0;
    temp[len++] = b[0];
    for (int i = 1; i < n; i++) {
        if (b[i] >= temp[len - 1]) {
            temp[len++] = b[i];
        } else {
            *std::lower_bound(temp, temp + len, b[i]) = b[i];
            // int* p = std::lower_bound(temp, temp + len, b[i]);
            // if (p == temp + len - 1) {
            //     *p = b[i];
            // }
        }
    }

    return len;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> a;
        mapping[a] = mapping[a] ? mapping[a] : i;
    }

    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        b[i] = mapping[b[i]];
    }

    std::cout << reslove() << "\n";;
}
