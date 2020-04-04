#include <iostream>
#include <iterator>
#include <algorithm>
#include <random>
#include <chrono>

int n, k;
int arr[5000005];
int arrCopy[5000005];

template <typename RanIt>
inline RanIt partition(RanIt first, RanIt last) {
	if (first == last) return first;

	--last; // pivot
	RanIt it = first;

	for (; it != last; ++it) {
		if (*it < *last) std::iter_swap(first++, it);
	}

	std::iter_swap(first, last);
	return first;
}

template <typename RanIt>
void nthElement(RanIt first, RanIt nth, RanIt last) {
	auto pivot = partition(first, last);
	auto distance = std::distance(pivot, nth);

	if (distance > 0)
		nthElement(pivot, pivot + distance, last);
	else if (distance < 0)
		nthElement(first, nth, pivot);
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
	nthElement(arr, arr + k, arr + n);
	auto time1 = std::chrono::high_resolution_clock::now() - begin;

	begin = std::chrono::high_resolution_clock::now();
	std::nth_element(arrCopy, arrCopy + k, arrCopy + n);
	auto time2 = std::chrono::high_resolution_clock::now() - begin;

	std::cout << arr[k] << "\n";
	std::cout << arrCopy[k] << "\n";
	std::cout << "nthElement: \t\t" << time1.count() << "ns\n";
	std::cout << "std::nth_element: \t" << time2.count() << "ns\n";
}