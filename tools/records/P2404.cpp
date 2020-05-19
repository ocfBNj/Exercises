#include <iostream>
#include <vector>

int n;
void f(int b, int n , std::vector<int> v)
{
	
		for (int i = b; i <= n / 2; i++) {
std::vector<int> temp = v;
temp.pop_back();
temp.push_back(i);
temp.push_back(n - i);
			f(i, n - i, std::move(temp));
		}
		
if (v.size() != 1) {
for (int i=0; i<v.size(); i++){
if (!i) {
std::cout << v[i];
} else {
std::cout << '+'<< v[i];
}

}
std::cout << std::endl;
	}
	

}

int main()
{
std::cin >> n;
std::vector<int> t{n};
//t.push_back(n);
	f(1, n, t);
}