#include <iostream>
using namespace std;

int main() {
    int M;
    cin >> M;
    int ball = 1;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        if (ball == a) {
            ball = b;
        } else if (ball == b) {
            ball = a;
        }
    }
    cout << ball;
    return 0;
}
