#include <iostream>
#include <list>

int n, m;
int k, p;
int x;
std::list<int>::iterator its[100008];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n;

    std::list<int> li{1};
    its[1] = li.begin();

    for (int i = 2; i <= n; i++) {
        std::cin >> k >> p;

        std::list<int>::iterator it = its[k];
        if (p == 1) {
            ++it;
        }

        its[i] = li.insert(it, i);
    }

    std::cin >> m;

    for (int i = 0; i != m; i++) {
        std::cin >> x;

        if (its[x] != li.end()) {
            li.erase(its[x]);
            its[x] = li.end();
        }
    }

    std::size_t size = li.size();

    for (int elem : li) {
        std::cout << elem;
        if (--size != 0) {
            std::cout.put(' ');
        }
    }

    std::cout.put('\n');
}