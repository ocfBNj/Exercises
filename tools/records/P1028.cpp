#include <iostream>

int vec[1000]{};

int func(int num) {
    int count = 0;
    if (vec[num - 1] != 0) {
        return vec[num - 1];
    }

    if (num > 1) {
        count += num / 2;
        for (int i = 2; i <= num / 2; i++) {
            count += func(i);
        }
        
    }
    vec[num - 1] = count;
    return count;
}

int main() {
    int num;
    std::cin >> num;

    num = num < 0 ? -num : num;


    std::cout << func(num) + 1 << std::endl;
}