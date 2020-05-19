#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

std::string A;
std::string B;
std::unordered_multimap<std::string, std::string> rules;
std::unordered_set<std::string> used;
std::queue<std::pair<std::string, char>> q;
int res = -1;

void reslove() {
    q.emplace(A, 0);
    while (!q.empty()) {
        auto [str, c] = q.front();
        q.pop();

        if (used.find(str) != used.end()) continue;

        used.insert(str);
        if (str == B) {
            res = c;
            return;
        }

        for (auto& [a, b] : rules) {
            std::string temp;
            std::size_t pos = -a.size();
            while (true) {
                temp = str;
                if ((pos = str.find(a, pos + a.size())) != std::string::npos) {
                    temp.replace(pos, a.size(), b);
                    // std::cout << "str: " << str << " c: " << (int)c << " temp: " << temp << "\n";
                    if (c + 1 <= 10)
                        q.emplace(temp, c + 1);
                } else {
                    break;
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> A >> B;
    std::string a1, b1;
    while (std::cin >> a1 >> b1) {
        rules.emplace(a1, b1);
    }

    reslove();
    if (res == -1) {
        std::cout << "NO ANSWER!\n";
    } else {
        std::cout << res << "\n";
    }
    
}
