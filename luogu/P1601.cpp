#include <iostream>
#include <string>

inline int ctoi(char c) {
    return c - '0';
}

inline char itoc(int i) {
    return '0' + i;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    std::string a, b;
    std::string result;

    std::cin >> a >> b;

    std::size_t i, j;
    int carry = 0; // 进位
    int _a, _b;
    int temp;
    for (i = a.size() - 1, j = b.size() - 1; i != -1 && j != -1; i--, j--) {
        _a = ctoi(a.at(i));
        _b = ctoi(b.at(j));
        temp = (_a + _b + carry) % 10;
        carry = (_a + _b + carry) / 10;
        result.push_back(itoc(temp));
    }

    if (i == -1) {
        for (; j != -1; j--) {
            _b = ctoi(b.at(j));
            temp = (_b + carry) % 10;
            carry = (_b + carry) / 10;
            result.push_back(itoc(temp));
        }
    } else {
        for (; i != -1; i--) {
            _a = ctoi(a.at(i));
            temp = (_a + carry) % 10;
            carry = (_a + carry) / 10;
            result.push_back(itoc(temp));
        }
    }

    if (itoc(carry) > '0') {
        result.push_back(itoc(carry));
    }

    for (auto it = result.rbegin(); it != result.rend(); ++it) {
        std::cout << *it;
    }
    
    std::cout << '\n';
}
