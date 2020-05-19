#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <cctype>
#include <sstream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	string word, temp;
	std::unordered_map<string, int> s;
	std::set<string> input;
	std::set<string> res;

	while (cin >> word) {
		if (word == "#") break;
		temp = word;
		std::for_each(temp.begin(), temp.end(), [](char& c) {
			c = std::tolower(c);
			});
		std::sort(temp.begin(), temp.end());

		if (s.find(temp) == s.end()) {
			s.insert(std::make_pair(temp, 1));
		} else {
			s[temp]++;
		}
		input.insert(word);
	}

	for (auto& word : input) {
		temp = word;
		std::for_each(temp.begin(), temp.end(), [](char& c) {
			c = std::tolower(c);
			});
		std::sort(temp.begin(), temp.end());
		if (s[temp] == 1) {
			res.insert(word);
		}
	}

	for (const string& word : res) {
		cout << word << endl;
	}
}