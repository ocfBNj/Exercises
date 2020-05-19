#include <iostream>
#include <queue>

int disjoint_set[104];

struct Edge {
	Edge(int _i = 0, int _j = 0, int _w = 0) : i(_i), j(_j), w(_w) {}
	int i;
	int j;
	int w;

	friend bool operator<(const Edge& lhs, const Edge& rhs) {
		return lhs.w > rhs.w;
	}
};

bool com(const Edge& lhs, const Edge& rhs) {
	return lhs.w < rhs.w;
}

int find_set(int num) {
	if (num != disjoint_set[num])
		num = find_set(disjoint_set[num]);

	return num;
}

inline void union_set(int lhs, int rhs) {
	int lp = find_set(lhs);
	int rp = find_set(rhs);

	disjoint_set[lp] = rp;
}

int main() {
	int n, k;
	int i, j, w;
	int res = 0;
	std::priority_queue<Edge> que;

	std::cin >> n >> k;

	while (k--) {
		std::cin >> i >> j >> w;
		que.push(Edge(i, j, w));
		res += w;
	}

	//自环 
	for (int i = 1; i <= n; i++) {
		disjoint_set[i] = i;
	}
	Edge temp;
	while (!que.empty()) {
		temp = que.top();
		que.pop();

		if (find_set(temp.i) != find_set(temp.j)) {
			res -= temp.w;
			union_set(temp.i, temp.j);
		}
	}


	std::cout << res << std::endl;
}