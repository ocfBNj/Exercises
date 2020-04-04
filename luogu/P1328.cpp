#include <iostream>

int n, nA, nB;
int arr[5][5];
int A[201];
int B[201];
int resA, resB;

int main() {
    std::ios_base::sync_with_stdio(false);

    arr[0][1] = -1;
    arr[1][0] = 1;

    arr[0][2] = 1;
    arr[2][0] = -1;

    arr[0][3] = 1;
    arr[3][0] = -1;

    arr[0][4] = -1;
    arr[4][0] = 1;

    arr[1][2] = -1;
    arr[2][1] = 1;

    arr[1][3] = 1;
    arr[3][1] = -1;

    arr[1][4] = -1;
    arr[4][1] = 1;

    arr[2][3] = -1;
    arr[3][2] = 1;

    arr[2][4] = 1;
    arr[4][2] = -1;

    arr[3][4] = 1;
    arr[4][3] = -1;

    std::cin >> n >> nA >> nB;
    for (int i = 0; i < nA; i++)
        std::cin >> A[i];
    for (int i = 0; i < nB; i++)
        std::cin >> B[i];

    for (int i = 0; i < n; i++) {
        int tempA = A[i % nA];
        int tempB = B[i % nB];
        if (arr[tempA][tempB] == 1)
            resA++;
        else if (arr[tempA][tempB] == -1)
            resB++;
    }

    std::cout << resA << " " << resB << "\n";
}
