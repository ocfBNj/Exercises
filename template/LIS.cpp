// TODO
#include <iostream>
#include <algorithm>

int arr[] = {5, 3, 1, 4, 1, 4, 9};
int help[100];

int lis() {
    int len = 0;
    help[len++] = arr[0];
    for (int i = 1; i < 7; i++) {
        if (arr[i] >= help[len - 1]) {
            help[len++] = arr[i];
        } else {
            *std::lower_bound(help, help + len, arr[i]) = arr[i];
        }
    }

    return len;
}

int main() {
    std::cout << lis() << "\n";
}
