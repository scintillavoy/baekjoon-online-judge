#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < 4*N - 3; ++i) {
        for (int j = 0; j < 4*N - 3; ++j) {
            if ((i % 2 == 0 && abs(2*N - 2 - j) <= abs(2*N - 2 - i))
                || (j % 2 == 0 && abs(2*N - 2 - j) >= abs(2*N - 2 - i))) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
