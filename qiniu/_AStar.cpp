#include <iostream>
#include <cmath>
#include <list>
#include <algorithm>

constexpr auto ROWS = 5;
constexpr auto COLS = 10;

struct Position;

std::list<Position> open_list;
std::list<Position> close_list;

Position* end;

char map[ROWS][COLS + 1] = {
    "1111000111",
    "1000010001",
    "1000010001",
    "1000010001",
    "1111000111"
};

struct Position {
    Position(int r = 0, int c = 0, int g = 0)
        : row(r), col(c), G(g),
        H(std::abs(col - end->col) + std::abs(row - end->row)) {}

    // 用于构造终点
    Position(int r, int c, bool is_end) : row(r), col(c), G(), H() {}

    int row;
    int col;

    Position* prev = nullptr;

    int G; // 已经走过的步数
    int H; // 距地终点的步数

};

bool operator<(const Position& left, const Position& right) {
    return left.G + left.H < right.G + right.H;
}

std::ostream& operator<<(std::ostream& is, const Position& pos) {
    is << "(" << pos.row << ", " << pos.col << ")";
    return is;
}

bool operator==(const Position& left, const Position& right) {
    return left.row == right.row && left.col == right.col;
}

void set_begin_end() {
    int row;
    int col;

    std::cout << "请输入终点: ";
    std::cin >> row >> col;
    end = new Position(row, col, true);

    std::cout << "请输入出发点: ";
    std::cin >> row >> col;
    open_list.push_back(Position(row, col));
}

void __explore(std::list<Position>::iterator& prev, Position cur) {
    // 1. 在关闭列表
    if (std::find(close_list.begin(), close_list.end(), cur) 
        != close_list.end()) {
        return;
    }

    // 2. 在开放列表
    else if (auto temp = std::find(open_list.begin(), open_list.end(), cur); 
        temp != open_list.end()) {
        // 判断R值是否更小
        if (1 + temp->H < prev->H) {
            temp->prev = &*prev;
        }
    }

    // 3. 未被探索的空地
    else {
        // 加入开放列表
        cur.prev = &(*prev);
        open_list.push_back(cur);
    }
}

void explore(std::list<Position>::iterator& cur) {
    int row = cur->row;
    int col = cur->col;
    int g = cur->G;
    int h = cur->H;

    if (row + 1 < ROWS && map[row + 1][col] == '0') {
        __explore(cur, Position(row + 1, col, g + 1));
    }

    if (row - 1 >= 0 && map[row - 1][col] == '0') {
        __explore(cur, Position(row - 1, col, g + 1));
    }

    if (col + 1 < COLS && map[row][col + 1] == '0') {
        __explore(cur, Position(row, col + 1, g + 1));
    }

    if (col - 1 >= 0 && map[row][col - 1] == '0') {
        __explore(cur, Position(row, col - 1, g + 1));
    }
}

bool resolve() {
    while (!open_list.empty()) {
        auto cur = std::min_element(open_list.begin(), open_list.end());
       
        if (cur->row == end->row && cur->col == end->col) {
            delete end;
            end = &(*cur);
            return true;
        }

        close_list.push_back(*cur);
        open_list.erase(cur);
        auto it = --close_list.end();
        explore(it);
    }

    delete end;
    return false;
}

void _print(Position* pos) {
    if (pos) {
        _print(pos->prev);
        std::cout << *pos << '\n';
    }
}

void print_result() {
    for (int i = 0; i < ROWS; i++) {
        std::cout << map[i] << '\n';
    }

    std::cout << "\n\n路径为: \n";
    _print(end);
}

int main() {
    set_begin_end();

    if (resolve())
        print_result();
    else
        std::cout << "未找到答案\n";

}
