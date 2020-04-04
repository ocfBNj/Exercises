#include <iostream>
#include <cctype>
#include <string>
#include <iterator>
#include <algorithm>

int p1, p2, p3;
std::string string;
bool used[101];

inline void print(char first, char last) {
    if (p3 == 1) {
        // 正序
        while (++first != last) {
            if (p1 == 1) {
                // 小写
                for (int i = 0; i < p2; i++)
                    std::cout.put(std::tolower(first));
            } else if (p1 == 2) {
                // 大写
                for (int i = 0; i < p2; i++)
                    std::cout.put(std::toupper(first));
            } else {
                // *
                for (int i = 0; i < p2; i++)
                    std::cout.put('*');
            }
        }
    } else {
        // 逆序
        while (--last != first) {
            if (p1 == 1) {
                // 小写
                for (int i = 0; i < p2; i++)
                    std::cout.put(std::tolower(last));
            } else if (p1 == 2) {
                // 大写
                for (int i = 0; i < p2; i++)
                    std::cout.put(std::toupper(last));
            } else {
                // *
                for (int i = 0; i < p2; i++)
                    std::cout.put('*');
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> p1 >> p2 >> p3;
    std::cin >> string;
    
    std::string::size_type begin = 0;

    while (begin != string.length()) {
        auto index = string.find('-', begin);
        if (index == std::string::npos) {
            std::copy(string.c_str() + begin, string.c_str() + string.length(), 
                std::ostream_iterator<char>(std::cout));
            break;
        }        

        if (index > 0 && index < string.length() - 1) {
            // 打印之前的
            std::copy(string.c_str() + begin, string.c_str() + index - 1, 
                std::ostream_iterator<char>(std::cout));

            auto f = string[index - 1];
            auto l = string[index + 1];

            if ( (std::isdigit(f) && std::isdigit(l) && f < l)
                || (std::isalpha(f) && std::isalpha(l) && f < l)) {

                if (!used[index - 1])
                    std::cout.put(f);

                print(f, l);

                std::cout.put(l);
                used[index + 1] = true;
                begin = index + 2;
            } else {
                // 不合法的-
                // 打印第一个
                if (!used[index - 1])
                    std::cout.put(f);
                // 打印-
                if (f != '-')
                    std::cout.put('-');
                begin = index + 1;
            }
        } else {
            // -在头部或尾部
            // 直接打印
            // 打印第一个
            if (index == begin) {
                if (!used[index])
                std::cout.put(string[index]);
            } else {
                std::copy(string.c_str() + begin, string.c_str() + index + 1, 
                    std::ostream_iterator<char>(std::cout));
            }

            begin = index + 1;
        }
    }
}
