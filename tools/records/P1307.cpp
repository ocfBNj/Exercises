#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n;
	bool is_f = false;
	cin >> n;
	if (n < 0) {
		is_f = true;
		n = -n;
	}
	string num = to_string(n);
	string r_num(num.rbegin(), num.rend());

	int res = atoi(r_num.c_str());
	if (is_f) res = -res;
	std::cout << res << endl;
}