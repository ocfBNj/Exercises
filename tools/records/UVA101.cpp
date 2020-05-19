#include <iostream>
#include <string>
#include <utility>
using std::string;
using std::cin;
using std::cout;
using std::endl;

#define SIZE 25

int table[SIZE][SIZE];
int size[SIZE];
int n;

std::pair<int, int> find_x(int x) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < size[i]; j++) {
			if (table[i][j] == x) {
				return std::make_pair(i, j);
			}
		}
	}
}

void reset_ceil(const std::pair<int, int>& point) {
	int _size = size[point.first];
	for (int i = point.second + 1; i < _size; i++) {
		int num = table[point.first][i];
		table[num][size[num]++] = num;
		size[point.first]--;
	}
}

void move_all(const std::pair<int, int>& B, const std::pair<int, int>& A) {
	int _size = size[A.first];
	for (int i = A.second; i < _size; i++) {
		int num = table[A.first][i];
		table[B.first][size[B.first]++] = num;
		size[A.first]--;
	}
}

int main() {
	string first, last;
	int a, b;

	cin >> n;

	for (int i = 0; i < n; i++) {
		size[i] = 1;
		table[i][0] = i;
	}

	while (true) {
		cin >> first;
		if (first == "quit") break;
		cin >> a >> last >> b;

		auto A = find_x(a);
		auto B = find_x(b);
		if (A.first == B.first) continue;
		if (first == "move") {
			if (last == "onto") {
				reset_ceil(A);
				reset_ceil(B);
				table[B.first][B.second + 1] = a;
				size[B.first]++;
				size[A.first]--;
			} else {
				reset_ceil(A);
				table[B.first][size[B.first]] = a;
				size[B.first]++;
				size[A.first]--;
			}

		} else {
			if (last == "onto") {
				reset_ceil(B);
				move_all(B, A);
			} else {
				move_all(B, A);
			}

		}
	}

	for (int i = 0; i < n; i++) {
		cout << i << ":";
		for (int j = 0; j < size[i]; j++) {
			cout << " " << table[i][j];
		}
		cout << endl;
	}
}