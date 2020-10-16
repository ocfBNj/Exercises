#include <iostream>
#include <algorithm>

int disjoint_set[10005];
int n, m;
int res;

struct Edge {
	Edge(int u_ = 0, int v_ = 0, int value_ = 0) : u(u_), v(v_), value(value_) {}
    int u, v;
    int value;
} edge[50005];

bool operator<(const Edge& lhs, const Edge& rhs) {
    return lhs.value < rhs.value;
}

void init_set() {
    // 构造自环
    for (int i = 0; i != n; i++) {
        disjoint_set[i] = i;
    }
}

int find_set(int i) {
    if (disjoint_set[i] != i) {
        disjoint_set[i] = find_set(disjoint_set[i]);
    }

    return disjoint_set[i];
}

void union_set(int l, int r) {
    l = find_set(l);
    r = find_set(r);

    disjoint_set[l] = r;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n >> m;
    init_set();
    int x, y, z;
    for (int i = 0; i != m; i++) {
        std::cin >> x >> y >> z;
        edge[i] = Edge(x - 1, y - 1, z);
    }

    std::sort(edge, edge + m);

    // 对于每条边
    int j = 0;
    for (int i = 0; i != m; i++) {
		Edge e = edge[i];
		int x = e.u;
		int y = e.v;
		int value = e.value;
        if (find_set(x) != find_set(y)) {
            union_set(x, y);
			if (value > res) {
				res = value;
			}
            j++;

            if (j == n - 1) {
                break;
            }
        }
    }

    std::cout << res;
}
