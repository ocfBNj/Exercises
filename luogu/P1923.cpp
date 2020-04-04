#include <iostream>
#include <iterator>
#include <algorithm>

int n, k;
int arr[5000005];

template <typename RandomAccessIterator>
inline RandomAccessIterator partition(RandomAccessIterator first, RandomAccessIterator last) {
	if (first == last) return first;

	std::advance(last, -1);
	auto pivot = *last;

	for (auto it = first; it != last; ++it) {
		if (*it < pivot) {
			std::iter_swap(first, it);
			++first;
		}
	}

	std::iter_swap(first, last);
	return first;
}

// 找到第k小的数（下标从0开始）
template <typename RandomAccessIterator>
void randomSelect(RandomAccessIterator first, RandomAccessIterator last, int i) {
	auto pivot = partition(first, last);
	auto dis = std::distance(first, pivot) + 1; // pivot距离first的距离
	if (dis == i + 1) {
		return;
	} else if (dis > i + 1) {
		randomSelect(first, pivot, i);
	} else {
		randomSelect(pivot + 1, last, i - dis);
	}
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n >> k;

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    randomSelect(arr, arr + n, k);
    std::cout << arr[k] << "\n";
}
