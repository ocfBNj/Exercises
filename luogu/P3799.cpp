#include <iostream>

constexpr auto mod = int(1e9 + 7);

int dic[5001];

inline int C(int m, int n) {
    return n == 1 ? m : m * (m - 1) / 2 % mod;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, temp;
    int res = 0;
    std::cin >> n;
    for (int i = 0; i != n; i++) {
        std::cin >> temp;
        ++dic[temp];
    }

    for (int num = 2; num != 5001; num++) {
        int count = dic[num];

        if (count >= 2) {
            temp = C(count, 2);

            for (int i = 1; i != num / 2 + 1; i++) {
                int j = num - i;

                if (i == j && dic[i] >= 2)
                    res = (res + temp * C(dic[i], 2)) % mod;
                if (i != j && dic[j] >= 1 && dic[i] >= 1)
                    res = (res + temp * C(dic[i], 1) % mod * C(dic[j], 1) % mod) % mod;
            }
        }
    }

    std::cout << res << "\n";
}
