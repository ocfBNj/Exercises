#include <iostream>
#include <cctype>
#include <stack>

int main() {
    std::stack<int> s;
    int num = 0;

    while (true) {
        char c = std::cin.get();
        if (c == '@') break;
        
        if (c == '.') {
            s.push(num);
            num = 0;
        } else if (std::isdigit(c)) {
            num = num * 10 + (c - '0');
        } else {
            int right = s.top();
            s.pop();
            int left = s.top();
            s.pop();

            switch (c) {
            case '+':
                s.push(left + right);
                break;
            case '-':
                s.push(left - right);
                break;
            case '*':
                s.push(left * right);
                break;
            case '/':
                s.push(left / right);
                break;
            default:
                break;
            }
        }
    }

    std::cout << s.top() << "\n";
}
