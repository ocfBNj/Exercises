#include <iostream>
#include <algorithm>
#include <string>

int main() {
    int n;
    int x;
    std::cin >> n >> x;

    std::string str;
    for (int i = 1; i <= n; i++) {
        str += std::to_string(i);
    }

    std::cout << std::count(str.begin(), str.end(), x + '0') << std::endl;
}