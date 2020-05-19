#include <vector>
#include <iostream>
#include <map>

std::map<int, int> mm[100004];
int results[100004];
int temp;

void dfs(int cur, int value) {
	for (std::pair<int, int> node : mm[cur]) {
		if (!results[node.first]) {
			temp = value ^ node.second;
			results[node.first] = temp;
			dfs(node.first, temp);
		}
	}
}

int main() {
	int n, m;
	int begin = 0, end;
	int value;

	std::cin >> n;
	while (--n) {
		std::cin >> begin >> end >> value;
		mm[begin][end] = value;
		mm[end][begin] = value;
	}

	int head = begin;
	results[head] = 0;

	dfs(head, 1);

	std::cin >> m;
	while (m--) {
		std::cin >> begin >> end;
		std::cout << (results[begin] ^ results[end]) << std::endl;
	}
}