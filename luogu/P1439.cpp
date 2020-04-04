#include <iostream>
#include <algorithm>

int a;
int b[100005];
int mapping[100005];
int n;

inline int resolve() {
    int len = 0;
    mapping[len++] = b[0];
    
    for (int i = 1; i < n; i++) {
        if (b[i] >= mapping[len - 1]) {
            mapping[len++] = b[i];
        } else {
            *std::lower_bound(mapping, mapping + len, b[i]) = b[i];
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

    std::cout << resolve() << "\n";;
}
