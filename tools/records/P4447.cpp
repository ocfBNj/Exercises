#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits>

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
    int min = std::numeric_limits<int>::max();
    for (const auto& q : ques) {
        if (q.size() < min) min = q.size();
    }

    return min;
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
