#include <iostream>
#include <limits>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int M;
        char type;
        cin >> M >> type;
        if (type == 'C') {
            char c;
            cin >> c;
            cout << c - 'A' + 1;
            for (int j = 1; j < M; ++j) {
                cout << ' ';
                cin >> c;
                cout << c - 'A' + 1;
            }
        } else if (type == 'N') {
            int c;
            cin >> c;
            cout << char(c + 'A' - 1);
            for (int j = 1; j < M; ++j) {
                cout << ' ';
                cin >> c;
                cout << char(c + 'A' - 1);
            }
        }
        cout << '\n';
    }
    return 0;
}
