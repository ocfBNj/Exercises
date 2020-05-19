#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

constexpr int N = 3;
int w[N] = {16, 15, 15};
int v[N] = {45, 25, 25};
int max_weight = 30;

// 回溯法
namespace cc1 {
    int result = 0;

    void resolve(int i = 0, int cur_value = 0, int cur_weight = 0) {
        if (i == N) {
            if (cur_value > result) result = cur_value;
        } else {
            resolve(i + 1, cur_value, cur_weight);
            if (w[i] <= max_weight - cur_weight) {
                resolve(i + 1, cur_value + v[i], cur_weight + w[i]);
            }
        }
    }
}

// 不带界的分枝限界法
namespace cc2 {
    int result = 0;

    void resolve() {
        struct Node {
            int i;
            int value;
            int weight;
        };

        std::queue<Node> que;
        que.push({0, 0, 0});

        while (!que.empty()) {
            std::cout << "cc2 que.size(): " << que.size() << "\n";

            Node node = que.front();
            que.pop();

            if (node.i == N) {
                if (node.value > result) result = node.value;
            } else {
                que.push({node.i + 1, node.value, node.weight});
                if (w[node.i] <= max_weight - node.weight) {
                    que.push({node.i + 1, node.value + v[node.i], node.weight + w[node.i]});
                }
            }
        }
    }
}

// 带界的分枝限界法
namespace cc3 {
    int result = 0;

    struct Node {
        int i{};
        int value{};
        int weight{};

        int ub{};       // 最大可以获得的价值
        bool used[N]{}; // 表示该物品是否可用
    };

    void set_ub(Node& node) {
        node.ub = node.value;
        int cur_weight = node.weight;
        int max_i = -1;

        bool temp[N];
        std::memcpy(temp, node.used, sizeof(temp));

        while (true) {
            for (int i = 0; i != N; i++) {
                if (!temp[i]) {
                    if (max_i == -1 || v[i] * w[max_i] > v[max_i] * w[i]) {
                        temp[i] = true;
                        max_i = i;
                    }
                }
            }

            if (max_i != -1) {
                if (cur_weight + w[max_i] > max_weight) {
                    break;
                }

                cur_weight += w[max_i];
                node.ub += v[max_i];
                max_i = -1;
            } else {
                break;
            }
        }

        if (max_i != -1) {
            node.ub += int((max_weight - cur_weight) * ((double)v[max_i] / w[max_i]));
        }
    }

    void resolve() {
        std::queue<Node> que;
        Node start;
        set_ub(start);

        que.push(start);

        while (!que.empty()) {
            std::cout << "cc3 que.size(): " << que.size() << "\n";

            Node node = que.front();
            que.pop();
            std::cout << "ub: " << node.ub << "\n";

            if (node.i == N) {
                if (node.value > result) result = node.value;
            } else {
                // 不选
                Node node1 = node;
                node1.used[node1.i] = true;
                set_ub(node1);
                if (node1.ub > result) {
                    node1.i++;
                    que.push(node1);
                }

                // 选
                if (w[node.i] <= max_weight - node.weight) {
                    node.value += v[node.i];
                    node.weight += w[node.i];
                    node.used[node.i] = true;
                    set_ub(node);

                    if (node.ub > result) {
                        node.i++;
                        que.push(node);
                    }
                }
            }
        }
    }
}

int main() {
    cc1::resolve();
    std::cout << cc1::result << "\n\n";

    cc2::resolve();
    std::cout << cc2::result << "\n\n";

    cc3::resolve();
    std::cout << cc3::result << "\n\n";
}