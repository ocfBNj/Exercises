#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Person {
	int w;
	int id;
};

Person persons[200005];
int E[11];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= 10; i++) {
		cin >> E[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> persons[i].w;
		persons[i].id = i;
	}

	sort(persons + 1, persons + n + 1, [](const Person& l, const Person& r) {
		if (l.w != r.w) return l.w > r.w;
		else return l.id < r.id;
		});

	for (int i = 1; i <= n; i++) {
		persons[i].w += E[((i - 1) % 10) + 1];
	}

	sort(persons + 1, persons + n + 1, [](const Person& l, const Person& r) {
		if (l.w != r.w) return l.w > r.w;
		else return l.id < r.id;
		});

	for (int i = 1; i <= k; i++) {
		cout << persons[i].id << ' ';
	}
}