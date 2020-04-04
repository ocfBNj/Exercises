#include <iostream>
#include <algorithm>

int arr[500005];
int n;

// 7 5 3    4 2 1
long long merge(int first, int mid, int last) {
    long long ret = 0;
    int count = last - first;
    if (count < 2) return 0;
    int* temp = new int[count];
    int i = first;
    int j = mid;
    int k = 0;

    while (i != mid && j != last) {
        if (arr[i] > arr[j]) {
            ret += last - j;
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    if (i != mid) std::move(arr + i, arr + mid, temp + k);
    else std::move(arr + j, arr + last, temp + k);

    std::move(temp, temp + count, arr + first);
    delete[] temp;

    return ret;
}

long long resolve(int first, int last) {
    if (last - first < 2) return 0;

    int mid = (last + first) / 2;
    long long ret = 0;
    ret += resolve(first, mid);
    ret += resolve(mid, last);
    ret += merge(first, mid, last);
    
    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << resolve(0, n) << "\n";
}
