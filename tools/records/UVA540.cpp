#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using std::string;
using std::cin;
using std::cout;
using std::endl;

std::unordered_map<int, int> persons;

int main() {
	int team;
	int count;
	string command;
	int id;
	int m = 1;
	while (cin >> team) {
		if (team == 0) break;
		persons.clear();
		for (int i = 0; i < team; i++) {
			cin >> count;
			for (int j = 0; j < count; j++) {
				cin >> id;
				persons.insert(std::make_pair(id, i));
			}
		}

		std::queue<int> team[1001];
		std::queue<int> que;

		cout << "Scenario #" << m << endl;
		m++;
		while (cin >> command) {
			if (command == "STOP") {
				cout << endl;
				break;
			}

			if (command == "ENQUEUE") {
				cin >> id;
				int t = persons.at(id);
				if (team[t].empty()) {
					que.push(t);
				}
				team[t].push(id);
			} else {
				int t = que.front();
				while (team[t].empty()) {
					que.pop();
					t = que.front();
				}
				cout << team[t].front() << endl;
				team[t].pop();
			}
		}
	}

}