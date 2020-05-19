#include <iostream>
#include <string>
#include <sstream>

int main()
{
	int n;
	bool flag;
	bool is_first;
	std::string str;
	std::string res;
	std::cin >> n;
	getchar();

	for (int i = 0; i < n; i++) {
		std::getline(std::cin, str);
		std::istringstream words(str);

		std::string word;
		is_first = true;
		while (words >> word) {
			if (is_first) {
				if (std::isupper(word[0])) {
					flag = true;
				} else {
					flag = false;
				}
				res += word;
				is_first = false;
				continue;
			}

			if (flag) {
				if (std::isupper(word[0]))
					word[0] = word[0] - 'A' + 'a';
			} else {
				if (!std::isupper(word[0]))
					word[0] = word[0] - 'a' + 'A';
			}

			res += word;
		}

		std::cout << res << std::endl;
		res = "";
		flag = false;
	}



	return 0;
}