#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <cctype>
#include <sstream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	string word;
	std::set<string> res;

	while (cin >> word) {
		std::for_each(word.begin(), word.end(), [](char& c) {
			if (std::isalpha(c)) {
				c = std::tolower(c);
			} else {
				c = ' ';
			}
			});

		std::istringstream in(word);
		string r_word;
		while (in >> r_word) {
			res.insert(r_word);
		}

	}

	for (auto& word : res) {
		cout << word << endl;
	}
}