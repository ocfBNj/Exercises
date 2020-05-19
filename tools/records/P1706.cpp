#include <iostream>
#include <set>
#include <iomanip>
#include <vector>

void func(const std::vector<int>& arr, const std::set<int>& s) {
    if (!s.empty()) {
        for (auto it = s.begin(); it != s.end(); it++) {
            std::set<int> temp_s = s;
            temp_s.erase(*it);
            std::vector<int> temp_arr = arr;
            temp_arr.push_back(*it);

            func(temp_arr, temp_s);
        }
    } else {
        for (auto num : arr) {
            std::cout << std::setw(5) << num;
        }
        std::cout << std::endl;
    }

}

int main() {
    int n = 0;
    std::cin >> n;
    std::set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    func(std::vector<int>(), s);
}