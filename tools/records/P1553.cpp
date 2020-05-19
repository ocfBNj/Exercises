#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string reverse(const string& num) {
	string res(num.rbegin(), num.rend());
	long long ret = atoll(res.c_str());
	return to_string(ret);
}

int main() {
	string num;
	string res;
	cin >> num;
	auto pos = num.find_first_of("./%");
	if (pos == string::npos) {
		res = reverse(num);
	} else {
		if (num[pos] == '.') {
			res += reverse(num.substr(0, pos)) + ".";
			string temp = reverse(num.substr(pos + 1));
			temp = reverse(temp);
			temp = reverse(temp);
			res += temp;
		} else if (num[pos] == '/') {
			res += reverse(num.substr(0, pos)) + "/" + reverse(num.substr(pos + 1));
		} else {
			res += reverse(num.substr(0, pos)) + "%";
		}
	}

	cout << res << endl;
}