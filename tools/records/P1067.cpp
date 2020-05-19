#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    int n;
    bool isFirst = true;
    std::cin >> n;

    while (n >= 0) {
        int num;
        std::cin >> num;

        if (num) {
            if (num == -1 && n != 0)
                std::cout.put('-');
            else if (num == 1 && n != 0 && !isFirst)
                std::cout.put('+');
            else if (num == 1 && isFirst && n != 0)
                ;
            else
                std::cout << num;
            
            if (num) {
                if (n > 1) {
                    std::cout << "x^" << std::noshowpos << n;
                } else if (n == 1) {
                    std::cout << "x";
                }
            }

            std::cout << std::showpos;
            isFirst = false;
        }

        n--;
    }
}
