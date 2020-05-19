#include <iostream>
#include <bitset>

long long cacl(long long a, long long b, long long n) {
    std::bitset<32> bit(b);
    long long ret = 1;

    for (int i = 31; i >= 0; i--) {
        ret = (ret * ret) % n;
        if (bit.test(i)) {
            ret = (ret * a) % n;
        }
    }

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    long long a, b, n;
    std::cin >> a >> b >> n;
    std::cout << a << "^" << b << " mod " << n << "=" << cacl(a, b, n) << "\n";
}
