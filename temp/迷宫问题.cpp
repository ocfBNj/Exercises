#include <iostream>
#include <queue>
#include <memory>
#include <vector>

constexpr int ROWS = 5;
constexpr int COLS = 5;

struct Position {
    Position(int x_, int y_, Position* p_)
        : x(x_), y(y_), p(p_) {}
    int x;
    int y;
    Position* p;
};

std::vector<std::unique_ptr<Position>> store_ptr;
std::vector<std::vector<Position*>> results;

bool operator==(const Position& lhs, const Position& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

std::ostream& operator<<(std::ostream& os, const Position& pos) {
    os << "(" << pos.x << ", " << pos.y << ")";

    return os;
}

char map[ROWS][COLS] = {
    0, 1, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0
};

void store_path(Position* pos) {
    if (pos) {
        store_path(pos->p);
        results.back().push_back(pos);
    }
}

bool can_go(Position* src, Position* des) {
    if (des->x < 0 || des->y < 0 || des->x >= ROWS || des->y >= COLS
        || map[des->x][des->y]) {
        return false;
    }

    // 不能往回走
    Position* p = src;
    while (p) {
        if (*p == *des) return false;
        p = p->p;
    }

    return true;
}

void resolve() {
    std::queue<Position*> que;
    auto begin = std::make_unique<Position>(0, 0, nullptr);

    if (can_go(nullptr, begin.get())) {
        que.push(begin.get());
        store_ptr.emplace_back(std::move(begin)); 
    }

    while (!que.empty()) {
        Position* pos = que.front();
        que.pop();

        if (pos->x == ROWS - 1 && pos->y == COLS - 1) {
            results.push_back(std::vector<Position*>());
            store_path(pos);
        } else {
            auto up = std::make_unique<Position>(pos->x - 1, pos->y, pos);
            if (can_go(pos, up.get())) {
                que.push(up.get());
                store_ptr.emplace_back(std::move(up));
            }

            auto down = std::make_unique<Position>(pos->x + 1, pos->y, pos);
            if (can_go(pos, down.get())) {
                que.push(down.get());
                store_ptr.emplace_back(std::move(down));
            }

            auto left = std::make_unique<Position>(pos->x, pos->y - 1, pos);
            if (can_go(pos, left.get())) {
                que.push(left.get());
                store_ptr.emplace_back(std::move(left));
            }

            auto right = std::make_unique<Position>(pos->x, pos->y + 1, pos);
            if (can_go(pos, right.get())) {
                que.push(right.get());
                store_ptr.emplace_back(std::move(right));
            }
        }
    }
}

void print_results() {
    if (results.empty()) {
        std::cout << "找不到，再见\n";
    } else {
        for (const auto& result : results) {
            for (const Position* pos : result) {
                std::cout << *pos << " ";
            }
            std::cout << "\n";
        }
    }
}

int main() {
    resolve();
    print_results();
}
