#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N % 2 == 0) {
        cout << "I LOVE CBNU";
    } else {
        for (int i = 0; i < N; ++i) {
            cout << '*';
        }
        cout << '\n';
        
        for (int i = 1; i < (N + 1) / 2; ++i) {
            cout << ' ';
        }
        cout << '*';
        cout << '\n';

        for (int i = 1; i < (N + 1) / 2; ++i) {
            for (int j = i + 1; j < (N + 1) / 2; ++j) {
                cout << ' ';
            }
            cout << '*';
            for (int j = 0; j < i * 2 - 1; ++j) {
                cout << ' ';
            }
            cout << '*';
            cout << '\n';
        }
    }
    return 0;
}
