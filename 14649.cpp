#include <iostream>
using namespace std;

int main() {
    int P, N;
    cin >> P >> N;
    int stone[100] = {0};

    while (N--) {
        int pos;
        char direction;
        cin >> pos >> direction;
        if (direction == 'L') {
            for (int i = pos - 2; i >= 0; --i) {
                stone[i] = (stone[i] + 1) % 3;
            }
        } else {
            for (int i = pos; i < 100; ++i) {
                stone[i] = (stone[i] + 1) % 3;
            }
        }
    }
    
    int cnt[3] = {0};
    for (auto const &x : stone) {
        ++cnt[x];
    }

    cout.precision(2);
    cout << fixed;
    for (auto const &x : cnt) {
        cout << P * (double) x / 100 << '\n';
    }
    return 0;
}
