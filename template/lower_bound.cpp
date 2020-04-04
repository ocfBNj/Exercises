#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>
#include <ctime>
#include <vector>

// 左闭右开区间[first, last)
int lowerBound(int arr[], int first, int last, int value) {
    int step;
    int ret = -1;
    while (first < last) {
        step = (last - first) / 2;
        if (arr[first + step] >= value) {
            last = first + step;
        } else {
            ret = first + step;
            first += step + 1;
        }
    }
    return ret;
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
}


int main() {
    int numbers[100];

    std::default_random_engine e(std::time(0));
    std::uniform_int_distribution dt(-100, 200);

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
        std::cout << "*std::lower_bound "  << *std::lower_bound(numbers, numbers + 100, temp) << "\n";
        std::cout << "*CC:lower_bound "  << *CC::lower_bound(numbers, numbers + 100, temp) << "\n";
        std::cout << "lowerBound "  << lowerBound(numbers, 0, 100, temp) << "\n";
    }
}
