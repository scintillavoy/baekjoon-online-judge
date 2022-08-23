#include <iostream>
using namespace std;

int main() {
    while (true) {
        int S;
        cin >> S;
        if (S == 0) {
            break;
        }
        cout << S << ' ';
        while (S / 10 > 0) {
            int mul = 1;
            do {
                mul *= S % 10;
            } while ((S /= 10) > 0);
            S = mul;
            cout << S << ' ';
        }
        cout << '\n';
    }
    return 0;
}
