#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Person {
	string name;
	int bonus;
};

Person persons[105];

int main() {
	int n;
	int avg_score;
	int class_score;
	char is_student;
	char is_west;
	int paper_count;
	int count_bonus = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> persons[i].name >> avg_score >> class_score >>
			is_student >> is_west >> paper_count;

		if (avg_score > 80 && paper_count >= 1) {
			persons[i].bonus += 8000;
		}

		if (avg_score > 85 && class_score > 80) {
			persons[i].bonus += 4000;
		}

		if (avg_score > 90) {
			persons[i].bonus += 2000;
		}

		if (avg_score > 85 && is_west == 'Y') {
			persons[i].bonus += 1000;
		}

		if (class_score > 80 && is_student == 'Y') {
			persons[i].bonus += 850;
		}

		count_bonus += persons[i].bonus;
	}

	stable_sort(persons, persons + n, [](const Person& l, const Person& r) {
		return l.bonus > r.bonus;
		});

	cout << persons[0].name << endl;
	cout << persons[0].bonus << endl;
	cout << count_bonus << endl;
}