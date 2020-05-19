#include <iostream>
#include <string>

int max;
int max_length;
int count;

void reslove(std::string&& cur_num) {
    if (cur_num.size() == max_length + 1) {
        return;
    } else {
        if (std::stoi(cur_num) <= max) {
            count++;
        }
    }
    
    reslove(cur_num + "0");
    reslove(cur_num + "1"); 
}

int main() {
    std::string n;
    std::cin >> n;
    max = std::stoi(n);
    max_length = n.size();

    reslove("1");

    std::cout << count << std::endl;
}
