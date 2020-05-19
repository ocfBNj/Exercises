#include <iostream>
#include <vector>

std::vector<int> vertexs[100005];
bool used[100005];

void dfs(std::vector<int>& vertex) {
	for (int i = 0; i != vertex.size(); i++) {
		if (!used[vertex[i]]) {
			used[vertex[i]] = true;
			dfs(vertexs[vertex[i]]);
		}
	}
}

int main() {
	int n, m;
	int l, r;
	std::cin >> n >> m;

	for (int i = 0; i < m; i++) {
		std::cin >> l >> r;
		vertexs[l].push_back(r);
		vertexs[r].push_back(l);
	}

	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			used[i] = true;
			dfs(vertexs[i]);
			count++;
		}
	}

	std::cout << count << std::endl;
}
