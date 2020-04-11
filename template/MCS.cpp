#include <iostream>
#include <algorithm>

int mcs(int* first, int* last) {
    int max = 0;
    int sum = 0;

    while (first != last) {
        sum += *first++;
        if (sum < 0) sum = 0;
        else if (sum > max) max = sum;
    }

    return max;
}

int mcs_(int* first, int* last) {
    if (first == last) return 0;
    if (last - first == 1) return *first > 0 ? *first : 0;

    int* mid = first + (last - first) / 2;
    int left_max = mcs_(first, mid);
    int right_max = mcs_(mid, last);

    int left = 0;
    int right = 0;
    int sum = 0;
    int* it = mid;

    while (it-- != first) {
        sum += *it;
        if (sum > left) left = sum;
    }

    sum = 0;
    while (mid != last) {
        sum += *mid++;
        if (sum > right) right = sum;
    }

    return std::max(std::max(left_max, right_max), left + right);
}

int main() {
    int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15};
    std::cout << mcs(std::begin(arr), std::end(arr)) << "\n";
    std::cout << mcs_(std::begin(arr), std::end(arr)) << "\n";
}
