#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            char p1, p2;
            cin >> p1 >> p2;
            if (p1 == 'R') {
                if (p2 == 'P') {
                    ++cnt;
                } else if (p2 == 'S') {
                    --cnt;
                }
            } else if (p1 == 'P') {
                if (p2 == 'R') {
                    --cnt;
                } else if (p2 == 'S') {
                    ++cnt;
                }
            } else if (p1 == 'S') {
                if (p2 == 'R') {
                    ++cnt;
                } else if (p2 == 'P') {
                    --cnt;
                }
            }
        }
        if (cnt < 0) {
            cout << "Player 1\n";
        } else if (cnt > 0) {
            cout << "Player 2\n";
        } else {
            cout << "TIE\n";
        }
    }
    return 0;
}
