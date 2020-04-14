#include <iostream>
#include <string>
#include <algorithm>

int arr[2001][2001];

std::string a;
std::string b;

int resolve() {
    std::size_t len_a = a.length();
    std::size_t len_b = b.length();

    for (int i = 1; i <= len_a; i++) {
        arr[i][0] = i;
    }

    for (int j = 1; j <= len_b; j++) {
        arr[0][j] = j;
    }

    for (int i = 1; i <= len_a; i++) {
        for (int j = 1; j <= len_b; j++) {
            if (a[i - 1] == b[j - 1]) {
                arr[i][j]= arr[i - 1][j - 1];
            } else {
                arr[i][j] = std::min(
                    std::min(arr[i - 1][j - 1] + 1, arr[i][j - 1] + 1), arr[i - 1][j] + 1);
            }
        }
    }

    return arr[len_a][len_b];
}

int main() {
    std::cin >> a >> b;
    std::cout << resolve() << "\n";
}
