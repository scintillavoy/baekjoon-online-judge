#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int size;
        cin >> size;
        if (size > 1) {
            for (int j = 0; j < size; ++j) {
                cout << '#';
            }
            cout << '\n';
        }
        for (int j = 0; j < size - 2; ++j) {
            cout << '#';
            for (int k = 0; k < size - 2; ++k) {
                cout << 'J';
            }
            cout << "#\n";
        }
        for (int j = 0; j < size; ++j) {
            cout << '#';
        }
        cout << "\n\n";
    }
    return 0;
}
