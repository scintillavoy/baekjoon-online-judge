#include <iostream>
using namespace std;

int main() {
    int N, R, C;
    cin >> N >> R >> C;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << ((i + j) % 2 == (R + C) % 2 ? 'v' : '.');
        }
        cout << '\n';
    }
    return 0;
}
