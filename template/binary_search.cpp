#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>
#include <ctime>
#include <vector>

// 左闭右开区间: [first, last)
int binarySearch(int arr[], int first, int last, int value) {
    int step;
    while (first < last) {
        step = (last - first) / 2;
        if (arr[first + step] == value) {
            return first + step;
        } else if (arr[first + step] < value) {
            first += step + 1;
        } else {
            last = first + step;
        }
    }

    return -1;
}

namespace CC {
    template <typename ForwardIt, typename T>
    ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value) {
        ForwardIt mid;
        typename std::iterator_traits<ForwardIt>::difference_type count, step;
        count = std::distance(first, last);

        while (count > 0) {
            mid = first;
            step = count / 2;
            std::advance(mid, step);
            if (*mid < value) {
                first = ++mid;
                count -= step + 1;
            } else {
                count = step;
            }
        }

        return first;
    }

    template <typename ForwardIt, typename T>
    bool binary_search(ForwardIt first, ForwardIt last, const T& value) {
        first = lower_bound(first, last, value);
        return (!(first == last) && !(value < *first));
    }
}


int main() {
    int numbers[100];

    std::default_random_engine e(std::time(0));
    std::uniform_int_distribution dt(1, 200);

    std::cout << "[ ";
    for (int i = 0; i < 100; i++) {
        std::cout << i << " ";
        numbers[i] = i;
    }
    std::cout << "]\n";

    // 测试10组数据
    for (int i = 0; i < 10; i++) {
        int temp = dt(e);
        std::cout << "\nCase " << i + 1 << ": " << temp << "\n";
        std::cout << "std::binary_search " << std::boolalpha << std::binary_search(numbers, numbers + 100, temp) << "\n";
        std::cout << "binarySearch " << std::boolalpha << binarySearch(numbers, 0, 100, temp) << "\n";
        std::cout << "CC:binary_search " << std::boolalpha << CC::binary_search(numbers, numbers + 100, temp) << "\n";
    }
}
