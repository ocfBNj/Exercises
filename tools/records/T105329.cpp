#include <iostream>
#include <set>

int main() {
	int n;
	int num;
	std::set<int> s;
	std::cin >> n;

	while (n--) {
		std::cin >> num;
		s.insert(num);
	}

	if (s.size() < 2)
		std::cout << "No answer" << std::endl;
	else {
		auto p = s.rbegin();
		int a = *p++;
		int b = *p;
		std::cout << a << " " << b << std::endl;
	}
}