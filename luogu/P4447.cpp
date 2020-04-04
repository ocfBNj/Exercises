#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

int n;
int a[100005];
std::vector<std::queue<int>> ques;

inline std::vector<std::queue<int>>::iterator findQues(int number) {
    auto first = ques.begin();
    auto last = ques.end();
    auto it = last;

    while (first != last) {
        if (first->back() == number - 1) {
            if (it == last) it = first;
            else if (first->size() < it->size()) {
                it = first;
            }
        }

        ++first;
    }

    return it;
}

inline int answer() {
    return std::min_element(ques.begin(), ques.end(), [](const auto& left, const auto& right){
        return left.size() < right.size();
    })->size();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a, a + n);

    for (int i = 0; i < n; i++) {
        auto q = findQues(a[i]);
        if (q == ques.end()) {
            std::queue<int> newQ;
            newQ.push(a[i]);
            ques.push_back(std::move(newQ));
        } else {
            q->push(a[i]);
        }
    }

    std::cout << answer() << "\n";
}
