#include <iostream>
using namespace std;

int main() {
    int sum = 0, min_odd = 101;
    for (int i = 0; i < 7; ++i) {
        int num;
        cin >> num;
        if (num % 2 == 1) {
            sum += num;
            if (num < min_odd) {
                min_odd = num;
            }
        }
    }
    if (sum == 0) {
        cout << "-1";
    } else {
        cout << sum << '\n' << min_odd;
    }
    return 0;
}
