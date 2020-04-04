#include <iostream>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);

    int N, C;
    long long count = 0;
    std::cin >> N >> C;
    std::unordered_map<long long, long long> s;

    int number;
    for (int i = 0; i < N; i++) {
        std::cin >> number;
        
        ++s[number];
    }
    
    for (auto it = s.begin(); it != s.end(); ++it) {
        auto p = s.find(it->first - C);
        if (p != s.end()) {
            count += p->second * it->second;
        }
    }

    std::cout << count << '\n';
}
