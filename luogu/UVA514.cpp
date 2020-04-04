#include <iostream>
#include <cstring>
#include <stack>

int numbers[1005];

int main() {
    while (true) {
        int n;
        std::cin >> n;
        if (n == 0) break;

        while (true) {
            memset(numbers, 0, sizeof numbers);

            // 读取数据
            for (int i = 0; i < n; i++) {
                std::cin >> numbers[i];
                if (numbers[0] == 0) break;
            }
            if (numbers[0] == 0) break;

            // 开始计算
            std::stack<int> temp;
            std::stack<int> r;
            for (int i = n; i >= 1; i--) {
                r.push(i);
            }

            int i = 0;
            for (; i < n; i++) {
                if (!temp.empty()) {
                    int item = temp.top(); 
                    if (item == numbers[i]) {
                        temp.pop();
                        continue;
                    }
                }

                if (!r.empty()) {
                    int item = r.top(); 
                    if (item != numbers[i]) {
                        // 暂存
                        temp.push(item);
                        i--;
                    }
                    r.pop();
                } else {
                    break;
                }
            }

            if (i != n) {
                std::cout << "No" << std::endl;
            } else {
                std::cout << "Yes" << std::endl;
            }
        }

        std::cout << std::endl;
    }

    return 0;
}
