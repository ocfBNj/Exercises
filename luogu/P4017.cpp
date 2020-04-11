#include <iostream>
#include <unordered_set>

std::unordered_set<int> childs[5000];
int saved[5000];
char not_root[5000];
int n, m;
int res;

// 计算当i作为食物链顶端时，食物链的条数
int resolve(int i) {
    if (saved[i]) {
        return saved[i];
    }

    int ret = 0;

    for (auto child : childs[i]) {
        saved[child] = resolve(child);
        ret = (ret + saved[child]) % 80112002;
    }

    saved[i] = !ret ? 1 : ret;
    return saved[i];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        childs[b - 1].insert(a - 1);
        not_root[a - 1] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!not_root[i]) {
            res = (res + resolve(i)) % 80112002;
        }
    }

    std::cout << res << "\n";
}
