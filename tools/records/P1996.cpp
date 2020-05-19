#include <iostream>
#include <list>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::list<int> list;
    for (int i = n; i != 0; i--) {
        list.push_front(i);
    }

    auto it = list.begin();

    while (!list.empty()) {
        for (int i = 0; i != m - 1; i++) {
            if (it == list.end()) it = list.begin();
            ++it;
            if (it == list.end()) it = list.begin();
        }

        std::cout << *it << " ";
        it = list.erase(it);
    }
}
