#include <iostream>
#include <algorithm>
#include <tuple>

int t, m;
std::tuple<int, int> items[10001];
int saved[100001];

int resolve(int time) {
    if (time > 0) {
        if (saved[time]) return saved[time];
        int ret = 0;
        for (int i = 0; i < m; i++) {
            const auto& [item_time, item_value] = items[i];
            if (time >= item_time) {
                ret = std::max(resolve(time - item_time) + item_value, ret);
            } else {
                break;
            }
        }

        saved[time] = ret;
        return ret;
    }

    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> t >> m;
    for (int i = 0; i < m; i++) {
        std::cin >> std::get<0>(items[i]) >> std::get<1>(items[i]);
    }

    std::sort(items, items + m, [](const auto& left, const auto& right){
        const auto& [l_t, l_m] = left;
        const auto& [r_t, r_m] = right;

        return l_t < r_t;
    });

    std::cout << resolve(t) << "\n";
}
