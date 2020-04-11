#include <iostream>

const int M = 5;
const int N = 3;

int A[M] = {4, 2, 5, 6, 1};
int B[N] = {2, 5, 7};
int arr[M + 1][N + 1];

void lcs() {
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (A[i - 1] == B[j - 1]) {
                arr[i][j] = arr[i - 1][j - 1] + 1;
            } else if (arr[i - 1][j] >= arr[i][j - 1]) {
                arr[i][j] = arr[i - 1][j];
            } else {
                arr[i][j] = arr[i][j - 1];
            }
        }
    }
}

void print_lcs(int i, int j) {
    if (i == 0 || j == 0) return;

    if (A[i - 1] == B[j - 1]) {
        print_lcs(i - 1, j - 1);
        std::cout << A[i - 1] << " ";
    } else if (arr[i - 1][j] >= arr[i][j - 1]) {
        print_lcs(i - 1, j);
    } else {
        print_lcs(i, j - 1);
    }
}

int main() {
    lcs();
    print_lcs(M, N);
}
