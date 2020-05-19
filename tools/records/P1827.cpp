#include <iostream>
#include <string>
#include <string_view>

struct Node {
    Node* left;
    Node* right;
    char data;
};

std::string z, q;

void construct(Node*& root, std::string_view z) {
    root = new Node{nullptr, nullptr, q[0]};
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
        print(root->left);
        print(root->right);
        std::cout << root->data;
    }
}

int main() {
    std::cin >> z >> q;
    Node* root;
    construct(root, z);
    print(root);
}