#include <algorithm>
#include <iostream>
#include <iterator>

int n, k;
int arr[5000005];

template <typename RandIt>
inline RandIt partition(RandIt first, RandIt last) {
    if (first == last) {
        return first;
    }

    std::advance(last, -1); // pivot

    for (RandIt it = first; it != last; std::advance(it, 1)) {
        if (*it <= *last) {
            std::iter_swap(first, it);
            std::advance(first, 1);
        }
    }

    std::iter_swap(first, last);
    return first;
}

template <typename RandIt>
void nth_element(RandIt first, RandIt nth, RandIt last) {
    auto pivot = partition(first, last);
    auto distance = std::distance(pivot, nth);

    if (distance > 0) {
        nth_element(pivot + 1, nth, last);
    } else if (distance < 0) {
        nth_element(first, nth, pivot);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n >> k;

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    nth_element(arr, arr + k, arr + n);
    std::cout << arr[k] << "\n";
}