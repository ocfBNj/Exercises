#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);

    std::string record;
    int W_count;
    int L_count;
    while (record.find_last_of('E') == std::string::npos) {
        std::string temp;
        std::cin >> temp;
        record.append(std::move(temp));
    }
    
    std::size_t size = record.find_last_of('E');
    std::size_t i;

    // 11分制
    for (i = 0, W_count = 0, L_count = 0; i < size; i++) {
        if (record.at(i) == 'W') W_count++;
        else L_count++;
        if (i && (W_count >= 11 || L_count >= 11) && std::abs(W_count - L_count) >= 2) {
            std::cout << W_count << ":" << L_count << '\n';
            W_count = L_count = 0;
        }
    }

    std::cout << W_count << ":" << L_count << "\n\n";

    // 21分制
    for (i = 0, W_count = 0, L_count = 0; i < size; i++) {
        if (record.at(i) == 'W') W_count++;
        else L_count++;
        if (i && (W_count >= 21 || L_count >= 21) && std::abs(W_count - L_count) >= 2) {
            std::cout << W_count << ":" << L_count << '\n';
            W_count = L_count = 0;
        }
    }

    std::cout << W_count << ":" << L_count << '\n';
}
