#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
// #include <fstream>

int main() {
    std::vector<int> box;
    std::multiset<int> s;
    // std::ofstream os("temp_7.txt");
    int n;
    std::cin >> n;

    int format;
    while (n--) {
        std::cin >> format;

        if (format == 0) {
            // 入库
            int weight;
            std::cin >> weight;
            box.push_back(weight);
            s.insert(weight);
        } else if (format == 1) {
            // 出库
            if (!box.empty()) {
                s.erase(box.back());
                box.pop_back();
            }
        } else if (format == 2) {
            // 查询
            if (!box.empty()) {
                std::cout << *s.rbegin() << std::endl;
                // os << *s.rbegin() << std::endl;
            } else {
                std::cout << 0 << std::endl;
                // os << 0 << std::endl;
            }
            
        }
    }
}
