#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N > 2) {
        if (N % 2 == 1) {
            cout << '0';
            return 0;
        }
        N /= 2;
    }
    cout << '1';
    return 0;
}
