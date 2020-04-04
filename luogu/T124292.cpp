#include <iostream>
#include <string>

int count;
std::string number;
int number_i;


void cacl(std::string cur, std::size_t size, std::size_t max_size) {
    if (cur.size() == max_size) {
        if (std::stoi(cur.substr(1)) <= number_i) {
            count++;
        }
        return;
    }

    char c = cur.back() == '0' ? '1' : cur.back();
    for (; c <= '9'; c++) {
        cacl(cur + std::string(1, c), size + 1, max_size);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin >> number;
    number_i = std::stoi(number);

    for (std::size_t i = 1; i != number.size() + 1; i++) {
        cacl("0", 1, i + 1);
    }

    std::cout << count << '\n';
}
