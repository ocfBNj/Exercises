#include <iostream>
#include <unordered_set>
#include <memory>
#include <cstring>

bool dfs(const char* arr, int i, int j, int row, int col, bool* used, std::unordered_multiset<char> elements) {
    if (elements.size() == 0) return true;

    bool ret = false;
    if (i >= 0 && i < row && j >= 0 && j < col && !used[i * col + j]) {
        auto it = elements.find(arr[i * col + j]);
        if (it != elements.end()) {
            elements.erase(it);

            used[i * col + j] = true;
            
            ret = dfs(arr, i + 1, j, row, col, used, elements)
                    || dfs(arr, i - 1, j, row, col, used, elements)
                    || dfs(arr, i, j + 1, row, col, used, elements)
                    || dfs(arr, i, j - 1, row, col, used, elements);

            used[i * col + j] = false;
        }

    }

    return ret;
}

bool resolve(const char* arr, int row, int col, std::unordered_multiset<char> elements) {
    std::unique_ptr<bool[]> used = std::make_unique<bool[]>(row * col);
    std::memset(used.get(), 0, row * col * sizeof(bool));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (elements.find(arr[i * col + j]) != elements.end()) {
                if (dfs(arr, i, j, row, col, used.get(), elements)) return true;
            }
        }
    }

    return false;
}

int main() {
    char arr[] = "ABCDEF"
                 "DEFGHI";
    
    std::unordered_multiset<char> elements = {'A', 'H', 'Q'};
    std::cout << std::boolalpha << resolve(arr, 2, 6, elements) << std::endl;
}
