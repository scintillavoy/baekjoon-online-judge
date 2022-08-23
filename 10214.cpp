#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int score = 0;
        for (int j = 0; j < 9; ++j) {
            int a, b;
            cin >> a >> b;
            score += a;
            score -= b;
        }
        if (score > 0) {
            cout << "Yonsei";
        } else if (score < 0) {
            cout << "Korea";
        } else {
            cout << "Draw";
        }
        cout << '\n';
    }
    return 0;
}
