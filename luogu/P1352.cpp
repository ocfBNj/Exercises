#include <algorithm>
#include <iostream>
#include <vector>

int n;
int l, k;

struct node_t {
    int r;
    int p;
    std::vector<int> children;
};

node_t nodes[6004];
int res[6004][2];

void resolve(int root) {
    int children_select = 0;
    int children_no_select = 0;

    for (int child : nodes[root].children) {
        resolve(child);
        children_select += res[child][1];
        children_no_select += res[child][0];
    }

    res[root][0] = std::max(children_select, children_no_select);
    res[root][1] = children_no_select + nodes[root].r;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        std::cin >> nodes[i].r;
    }

    for (int i = 0; i != n - 1; i++) {
        std::cin >> l >> k;
        nodes[k].children.push_back(l);
        nodes[l].p = k;
    }

    int root = static_cast<int>(
        std::find_if(nodes + 1, nodes + 1 + n, [](node_t& node) { return node.p == 0; }) - nodes);
    resolve(root);

    std::cout << std::max(res[root][0], res[root][1]) << "\n";
}