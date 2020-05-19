#include <iostream>

using namespace std;

int main() {
    int time;
    int count = 0;
    int max = 0;
    int n = 0;
    bool isHappy = true;

    for (int i = 0; i < 7; i++) {
        cin >> time;
        count += time;
        cin >> time;
        count += time;
        if (count > 8) {
            isHappy = false;
            if (count > max) {
                max = count;
                n = i + 1;
            }
        }
        count = 0;
    }

    cout << (isHappy ? 0 : n) << endl;
}