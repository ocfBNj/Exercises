#include <iostream>
#include <string>

inline std::string join(const std::string& left, const std::string& right) {
    // std::cout << "left: " << left << " right: " << right << "\n";
    std::size_t lSize = left.size();
    std::size_t rSize = right.size();

    for (std::size_t i = lSize - 1; i != 0; i--) {
        std::size_t j = 0;
        for (int b = i; j < lSize - i && j < rSize; b++, j++) {
            if (left.at(b) != right.at(j)) break;
        }

        if (j == lSize - i) {
            return left.substr(0, i) + right;
        }
    }

    return std::string();
}

std::size_t res;
int n;
char c;
std::string arr[21];
char used[21];

void reslove(const std::string& str) {
    // std::cout << "str: " << str << "\n";
    bool isReturn = true;
    for (int i = 0; i < n; i++) {
        if (used[i] < 2) {
            std::string temp = join(str, arr[i]);
            if (temp.size()) {
                isReturn = false;
                used[i]++;
                reslove(temp);
                used[i]--;
            }
        }
    }

    if (isReturn) {
        if (str.size() > res) {
            res = str.size();
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cin >> c;

    for (int i = 0; i < n; i++) {
        if (arr[i].at(0) == c) {
            used[i]++;
            reslove(arr[i]);
            used[i]--;
        }
    }
    
    std::cout << res << "\n";
}
