#include <iostream>
#include <algorithm>

#define SIZE 50005

int disjoint_set[SIZE];

int find_set(int n)
{
	if (disjoint_set[n] != n) {
		n = find_set(disjoint_set[n]);
	}
	return n;
}

void union_set(int l, int r)
{
	int lp = find_set(l);
	int rp = find_set(r);

	disjoint_set[lp] = rp;
}

struct Edge {
    friend bool operator<(const Edge& lhs, const Edge& rhs);

    Edge(int _x, int _y , int _z) : x(_x), y(_y), z(_z) {}
    Edge() {}

    int x;
    int y;
    int z;
} edges[200005];

bool operator<(const Edge& lhs, const Edge& rhs)
{ return lhs.z < rhs.z; }

int main()
{
	int n, m;
    int res = 0;
    int count = 0;
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		disjoint_set[i] = i;
	}

	for (int i = 0; i < m; i++) {
		std::cin >> edges[i].x >> edges[i].y >> edges[i].z;
	}

    std::sort(edges, edges + m);

    for (int i = 0; i < m; i++) {
        if (find_set(edges[i].x) != find_set(edges[i].y)) {
            union_set(edges[i].x, edges[i].y);
            res += edges[i].z;
            count++;
            if (count + 1 == n) break;
        }
    }

    if (count + 1 == n) {
        std::cout << res << std::endl;
    } else {
        std::cout << "orz" << std::endl;
    }
}