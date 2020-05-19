#include <iostream>

using namespace std;

int main() {
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    int count = (h2 - h1) * 60 + (m2 - m1);
    cout << count / 60 << " " << count % 60;
}