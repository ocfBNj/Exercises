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

std::string mid, last;

void construct(std::unique_ptr<Node>& root, std::string_view mid) {
    root = std::make_unique<Node>(nullptr, nullptr, last.back());
    auto pos = mid.find(last.back());
    std::string_view left(mid.data(), pos);
    std::string_view right(mid.data() + pos + 1, mid.length() - pos - 1);
    last = std::string_view(last.data(), last.length() - 1);

    if (last.length() > 0 && right.find(last.back()) != std::string::npos) {
        construct(root->right, right);
    }
    
    if (last.length() > 0 && left.find(last.back()) != std::string::npos) {
        construct(root->left, left);
    }
}

void print(const Node* root) {
    if (root) {
        std::cout << root->data;
        print(root->left.get());
        print(root->right.get());
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> mid >> last;
    std::unique_ptr<Node> root;
    construct(root, mid);
    print(root.get());
}