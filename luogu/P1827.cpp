#include <iostream>
#include <string>
#include <string_view>
#include <memory>

struct Node {
    Node(Node* l, Node* r, char c) : left(l), right(r), data(c) {}
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    char data;
};

std::string z, q;

void construct(std::unique_ptr<Node>& root, std::string_view z) {
    root = std::make_unique<Node>(nullptr, nullptr, q[0]);
    auto pos = z.find(q[0]);
    std::string_view left(z.data(), pos);
    std::string_view right(z.data() + pos + 1, z.length() - pos - 1);
    q = std::string_view(q.data() + 1, q.length() - 1);
    
    if (q.length() > 0 && left.find(q[0]) != std::string::npos) {
        construct(root->left, left);
    }

    if (q.length() > 0 && right.find(q[0]) != std::string::npos) {
        construct(root->right, right);
    }
}

void print(const Node* root) {
    if (root) {
        print(root->left.get());
        print(root->right.get());
        std::cout << root->data;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> z >> q;
    std::unique_ptr<Node> root;
    construct(root, z);
    print(root.get());
}