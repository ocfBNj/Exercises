#include <iostream>
#include <algorithm>
using namespace std;

struct Score {
	int A;
	int B;
	int C;
	int sum;
	int i;
};

Score scores[305];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> scores[i].A >> scores[i].B >> scores[i].C;
		scores[i].i = i + 1;
		scores[i].sum = scores[i].A + scores[i].B + scores[i].C;
	}

	stable_sort(scores, scores + n, [](const Score& l, const Score& r) {
		return l.sum > r.sum;
		});

	for (int i = 0, j = 0; j < 5; ) {
		if (scores[i].sum != scores[i + 1].sum) {
			cout << scores[i].i << " " << scores[i].sum << endl;
			i++;
			j++;
		} else {
			Score* p = find_if(scores + i, scores + n, [=](const Score& s) {return s.sum != scores[i].sum; });
			stable_sort(scores + i, p, [](const Score& l, const Score& r) {
				return l.A > r.A;
				});
			while (j < 5 && scores + i != p) {
				cout << scores[i].i << " " << scores[i].sum << endl;
				i++;
				j++;
			}
		}
	}

}