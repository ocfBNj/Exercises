#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Apple {
	int height;
	int weight;
};

Apple apples[5005];

int main() {
	int n, s;
	int chair, hand;
	int res = 0;
	cin >> n >> s;
	cin >> chair >> hand;
	for (int i = 0; i < n; i++) {
		cin >> apples[i].height >> apples[i].weight;
	}

	auto end = remove_if(apples, apples + n, [=](const Apple& a) {
		return a.height > chair + hand;
		});

	n = end - apples;
	sort(apples, apples + n, [](const Apple& l, const Apple& r) {
		return l.weight < r.weight;
		});

	auto it = apples;
	while (it != apples + n) {
		if (s < it->weight) break;
		res++;
		s -= it->weight;
		it++;
	}
	cout << res << endl;
}