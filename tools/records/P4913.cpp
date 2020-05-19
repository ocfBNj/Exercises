#include <iostream>
#include <stack>
#include <algorithm>

int nodes[1000005][2];
int n;
int depth = 0;
int res = 0;

void dfs(int i) {
    if (i == 0) {
        res = std::max(depth, res);
        return;
    }

    depth++;
    dfs(nodes[i][0]);
    dfs(nodes[i][1]);
    depth--;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> nodes[i][0] >> nodes[i][1];
    }

    dfs(1);

    std::cout << res << "\n";
}