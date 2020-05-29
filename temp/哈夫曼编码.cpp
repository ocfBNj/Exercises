#include <iostream>
#include <memory>
#include <queue>
#include <vector>
#include <string>

struct Char {
    char c;
    int freq;
};

struct Node {
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    Char c;
};

bool comp(const std::unique_ptr<Node>& lhs, const std::unique_ptr<Node>& rhs) {
    return lhs->c.freq > rhs->c.freq;
}

template <typename It>
std::unique_ptr<Node> solve(It first, It last) {
    std::priority_queue<std::unique_ptr<Node>, std::vector<std::unique_ptr<Node>>,
        decltype(comp)*> que{comp};

    while (first != last) {
        auto node = std::make_unique<Node>();
        node->c = *first++;

        que.emplace(std::move(node));
    }

    while (que.size() > 1) {
        auto left = const_cast<std::unique_ptr<Node>&>(que.top()).release();
        que.pop();
        auto right = const_cast<std::unique_ptr<Node>&>(que.top()).release();
        que.pop();

        auto node = std::make_unique<Node>();

        node->left.reset(left);
        node->right.reset(right);
        node->c = {-1, left->c.freq + right->c.freq};

        que.emplace(std::move(node));
    }

    return std::unique_ptr<Node>{const_cast<std::unique_ptr<Node>&>(que.top()).release()};
}

void print(Node* node, std::string str = "") {
    if (node) {
        if (!node->left && !node->right) {
            std::cout << node->c.c << ": " << str << "\n";
        } else {
            print(node->left.get(), str + "0");
            print(node->right.get(), str + "1");
        }
    }
}

int main() {
    std::vector<Char> chars{{'f', 5}, {'e', 9}, {'c', 12}, {'b', 13}, {'d', 16}, {'a', 45}};
    auto root = solve(chars.begin(), chars.end());
    print(root.get());
}
