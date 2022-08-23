#include <iostream>
using namespace std;

#define LEN 100

int main() {
    int n, d;
    cin >> n >> d;

    // Get digits after the decimal point
    int digit[LEN], idx;
    for (idx = 0; idx < LEN; ++idx) {
        digit[idx] = 10 * n / d;
        if (digit[idx] == 0 || digit[idx] == 9) {
            break;
        }
        n = 10 * n % d;
    }

    // Print the result
    if (idx == 0) {
        cout << (digit[0] == 0 ? 0 : 1);
    } else if (idx == LEN) {
        cout << "throw out";
    } else {
        cout << "0.";
        for (int i = 0; i < idx-1; ++i) {
            cout << digit[i];
        }
        if (digit[idx] == 0) {
            cout << digit[idx-1];
        } else {
            cout << digit[idx-1]+1;
        }
    }
    cout << '\n';
    return 0;
}
