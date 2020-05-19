#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int ele;
    cin >> ele;
    cout.setf(ios::fixed);
    if (ele <= 150) {
        cout << setprecision(1) << ele * 0.4463 << endl;
    } else if (ele <= 400) {
        cout << setprecision(1) << 150 * 0.4463 + (ele - 150) * 0.4663 << endl;
    } else {
        cout << setprecision(1) << 150 * 0.4463 + 250 * 0.4663 + (ele - 400) * 0.5663 << endl;
    }
}