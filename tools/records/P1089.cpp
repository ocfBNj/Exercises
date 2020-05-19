#include <iostream>

using namespace std;

int main() {
    int count = 0;
    int interesting = 0;
    int money = 0;

    for (int i = 0; i < 12; i++) {
        count += 300;
        cin >> money;
        count -= money;
        if (count < 0) {
            cout << -(i + 1) << endl;
            return 0;
        }

        if (count >= 100) {
            interesting += (count / 100) * 100;
            count -= (count / 100) * 100;
        }
    }

    cout << count + (interesting) * 1.2 << endl;
}