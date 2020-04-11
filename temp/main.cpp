#include <iostream>
#include <string>
#include <algorithm>

int arr[100][100];
int saved[100][100];

std::string a = "sfdqxbw";
std::string b = "gfdgw";

int resolve(const std::string& a,  const std::string& b) {
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

int resolve(int i, int j) {
    if (i == 0) return j;
    if (j == 0) return i;
    if (saved[i][j]) return saved[i][j];

    if (a[i - 1] == b[j - 1]) {
        saved[i][j] = resolve(i - 1, j - 1);
    } else {
        saved[i][j] = std::min(
            std::min(resolve(i - 1, j - 1) + 1, resolve(i, j - 1) + 1), resolve(i - 1, j) + 1);
    }

    return saved[i][j];
}

int main() {
    std::cout << resolve(a, b) << "\n";
    std::cout << resolve(a.length(), b.length()) << "\n";
}