#include <iostream>
#include <cstddef>
#include <string>

using std::size_t;
 
int main() {
    std::ios_base::sync_with_stdio(false);

	std::string num1;
	std::string num2;
 
	std::cin >> num1 >> num2;
 
	size_t size1 = num1.size();
	size_t size2 = num2.size();
	size_t size_s = size1 + size2;
 
	std::string result(size_s, '0');
 
	int num = 0;      //当前位的值
	int over_num = 0; //进位
	int res = 0;      //每次相乘后得到的结果
  
	for (size_t i = 0; i < size2; i++) {
		num = num2[size2 - i - 1] - '0';

        size_t j = 0;
		for (; j < size1; j++) {
			res = num * (num1[size1 - j - 1] - '0') + 
				(result[size_s - i - j - 1] - '0') + over_num;
 
			result[size_s - i - j - 1] = res % 10 + '0';
 
			over_num = res / 10;
		}
 
		if (over_num) {
			result[size_s - i - j - 1] = over_num + '0';
		}
 
		over_num = 0;
	}
 
	bool flag = false;
    size_t size = result.size();
	for (size_t i = 0; i < size; i++) {
        if (i == size - 1 && result[i] == '0') {
            std::cout << result[i];
            break;
        }
        
		if (result[i] != '0' || flag) {
			flag = true;
			std::cout << result[i];
		}
	}
 
	std::cout << std::endl;
}