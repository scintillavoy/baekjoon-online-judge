#include <iostream>
using namespace std;

int main() {
    double temp_curr, temp_prev;
    cin >> temp_prev;
    cout.precision(2);
    cout << fixed << showpoint;
    while (true) {
        cin >> temp_curr;
        if (temp_curr == 999) {
            break;
        }
        cout << temp_curr - temp_prev << '\n';
        temp_prev = temp_curr;
    }
    return 0;
}
