#include <iostream>
#include <set>
#include <iterator>

std::multiset<int> s;

int main() {
    std::ios_base::sync_with_stdio(false);
    int n;
    int left, right;
    std::cin >> n;

    s.insert(-0x7fffffff);
    s.insert(+0x7fffffff);

    while (n--) {
        std::cin >> left >> right;

        switch (left) {
        case 1:
        {
            auto it = s.lower_bound(right);
            std::cout << std::distance(s.begin(), it) << '\n';
        }
        break;
        case 2:
        {
            auto it = s.begin();
            std::advance(it, right);
            std::cout << *it << '\n';
        }
        break;
        case 3:
        {
            auto it = s.lower_bound(right);
            std::cout << *std::prev(it) << '\n';
        }
        break;
        case 4:
            std::cout << *s.upper_bound(right) << '\n';
        break;
        case 5:
            s.insert(right);
            break;
        default:
            break;
        }
    }
}
