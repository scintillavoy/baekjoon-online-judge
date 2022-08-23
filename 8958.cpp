#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string buf;
    cin >> n;
    for (; n > 0; --n) {
        cin >> buf;
        int score = 0, cnt = 0;
        for (auto const &x : buf) {
            if (x == 'O') {
                score += ++cnt;
            } else {
                cnt = 0;
            }
        }
        cout << score << '\n';
    }
    return 0;
}
