#include <algorithm>
#include <cmath>
#include <iostream>

struct Node {
    Node* p;
    int size;
    int index;
};

void make_set(Node* node) {
    node->p = node;
    node->size = 1;
    node->index = 0;
}

Node* find_set(Node* node) {
    if (node != node->p) {
        Node* parent = node->p;
        node->p = find_set(node->p);
        node->index += parent->index;
    }

    return node->p;
}

void union_set(Node* lhs, Node* rhs) {
    Node* l = find_set(lhs);
    Node* r = find_set(rhs);

    l->p = r;
    l->index += r->size;
    r->size += l->size;
}

int between_node(Node* lhs, Node* rhs) {
    Node* l = find_set(lhs);
    Node* r = find_set(rhs);

    if (l != r) {
        return -1;
    }

    if (lhs->index == rhs->index) {
        return 0;
    }

    return std::abs(lhs->index - rhs->index) - 1;
}

Node nodes[30001];
int t;
char op;
int i, j;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> t;

    std::for_each(nodes + 1, nodes + 1 + 30000, [](Node& node) { make_set(&node); });

    for (int n = 0; n != t; n++) {
        std::cin >> op >> i >> j;
        if (op == 'C') {
            std::cout << between_node(&nodes[i], &nodes[j]) << "\n";
        } else {
            union_set(&nodes[i], &nodes[j]);
        }
    }
}