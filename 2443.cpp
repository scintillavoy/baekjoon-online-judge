#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = N - 1; i >= 0; --i) {
        for (int j = N - 1 - i; j > 0; --j) {
            cout << ' ';
        }
        for (int j = 0; j < 2 * i + 1; ++j) {
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}
