#include <algorithm>
#include <iostream>
#include <memory>

int arr[500005];
int n;

long long merge(int first, int mid, int last) {
    long long ret = 0;
    int count = last - first;

    if (count < 2) {
        return 0;
    }

    auto temp = std::make_unique<int[]>(count);
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

    if (i != mid) {
        std::copy(arr + i, arr + mid, temp.get() + k);
    } else {
        std::copy(arr + j, arr + last, temp.get() + k);
    }

    std::copy(temp.get(), temp.get() + count, arr + first);

    return ret;
}

long long resolve(int first, int last) {
    if (last - first < 2) {
        return 0;
    }

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