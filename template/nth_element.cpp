#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <random>

int n, k;
int arr[5000005];
int arrCopy[5000005];

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
    std::random_device rd;
    std::mt19937 e(rd());
    std::cin >> n >> k;
    std::uniform_int_distribution dt(-n, n);

    for (int i = 0; i < n; i++) {
        arr[i] = dt(e);
        arrCopy[i] = arr[i];
    }

    auto begin = std::chrono::high_resolution_clock::now();
    nth_element(arr, arr + k, arr + n);
    auto time1 = std::chrono::high_resolution_clock::now() - begin;

    begin = std::chrono::high_resolution_clock::now();
    std::nth_element(arrCopy, arrCopy + k, arrCopy + n);
    auto time2 = std::chrono::high_resolution_clock::now() - begin;

    std::cout << arr[k] << "\n";
    std::cout << arrCopy[k] << "\n";
    std::cout << "nth_element: \t\t" << time1.count() << "ns\n";
    std::cout << "std::nth_element: \t" << time2.count() << "ns\n";
}
