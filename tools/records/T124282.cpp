#include <iostream>
#include <string>
#include <cstddef>

inline bool isO(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::string str;
    std::cin >> str;
    std::size_t i = 0;
    std::size_t size = str.size();

    bool f1, f2, f3, f4;
    f1 = f2 = f3 = f4 = false;

    while (i != size && !isO(str.at(i))) {i++; f1 = true;}
    while (i != size && isO(str.at(i))) {i++; f2 = true;}
    while (i != size && !isO(str.at(i))) {i++; f3 = true;}
    while (i != size && isO(str.at(i))) {i++; f4 = true;}

    if (i == size && f1 && f2 && f3 && f4) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }
}
