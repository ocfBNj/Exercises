#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::unordered_set<int> s;
    std::string str[3];
    for (int i = 123; i <= 333; i++) {
        s.clear();
        s.insert('0');
        int j = i * 2;
        int k = i * 3;

        str[0] = std::to_string(i);
        str[1] = std::to_string(j);
        str[2] = std::to_string(k);

        for (auto &m : str) {
            for (int n = 0; n < 3; n++) {
                if (s.find(m[n]) == s.end()) {
                    s.insert(m[n]);
                } else {
                    goto b;
                }
            }
        }

        std::cout << str[0] + " " + str[1] + " " + str[2] << std::endl;

        b:;
    }
}