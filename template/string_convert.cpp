#include <iostream>
#include <string>
#include <sstream>

template <typename _Ty>
std::string toString(const _Ty& value) {
    std::ostringstream os;
    os << value;
    return os.str();
}

template <typename _Ty>
_Ty fromString(const std::string& str) {
    std::istringstream is(str);
    _Ty ret;
    is >> ret;
    return ret;
}

int main() {
    std::cout << toString(123) << '\n';
    std::cout << fromString<int>("123") << '\n';
}
