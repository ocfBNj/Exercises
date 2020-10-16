#include <algorithm>
#include <iostream>
#include <limits>

int n, m;
int x, y, t;

struct edge_t {
    int u, v;
    int value;
};

edge_t edges[100008];
int disjoint_set[1008];

void make_set() {
    for (int i = 1; i <= n; i++) {
        disjoint_set[i] = i;
    }
}

int find_set(int i) {
    if (i != disjoint_set[i]) {
        disjoint_set[i] = find_set(disjoint_set[i]);
    }

    return disjoint_set[i];
}

void union_set(int lhs, int rhs) {
    int l = find_set(lhs);
    int r = find_set(rhs);

    disjoint_set[l] = r;
}

int resolve() {
    make_set();
    std::sort(edges + 1, edges + 1 + m,
              [](const edge_t& lhs, const edge_t& rhs) { return lhs.value < rhs.value; });

    int res = std::numeric_limits<int>::min();
    int count = 0;
    int i = 1;

    while (i != 1 + m) {
        const edge_t& edge = edges[i++];
        if (find_set(edge.u) != find_set(edge.v)) {
            union_set(edge.u, edge.v);

            res = std::max(res, edge.value);

            if (++count == n - 1) {
                break;
            }
        }
    }

    if (count != n - 1) {
        res = -1;
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        std::cin >> edges[i].u >> edges[i].v >> edges[i].value;
    }

    std::cout << resolve() << "\n";
}