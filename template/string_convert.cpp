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

template <typename Des, typename Src>
Des convert_cast(const Src& src) {
    std::stringstream ss;
    ss << src;

    Des des;
    ss >> des;

    return des;
}

int main() {
    std::cout << convert_cast<std::string>(123) << "\n";
    std::cout << convert_cast<int>("123") << "\n";
    std::cout << toString(123) << '\n';
    std::cout << fromString<int>("123") << '\n';
}
