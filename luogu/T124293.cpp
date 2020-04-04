#include <iostream>
#include <map>
#include <algorithm>

int arr[1001];
int count;
std::multimap<int, int> m;

int main() {
    std::ios_base::sync_with_stdio(false);

    
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        m.insert(std::make_pair(arr[i], i));
    }

    int min = arr[0];
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > min) {
            if (std::find_if(arr + i + 1, arr + n, [&](int num){ return num > arr[i]; }) != arr + n) {
                count++;
            }

        } else {
            min = arr[i];
        }

        // if (std::find_if(arr + i + 1, arr + n, [&](int num){ return num > arr[i]; }) != arr + n
        // && std::find_if(arr, arr + i, [&](int num) { return num < arr[i]; }) != arr + i) {
        //         count++;
        // }
    }


    std::cout << count << '\n';
}
