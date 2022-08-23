#include <iostream>
using namespace std;

int main() {
    int S = 0, T = 0;
    for (int i = 0; i < 4; ++i) {
        int score;
        cin >> score;
        S += score;
    }
    for (int i = 0; i < 4; ++i) {
        int score;
        cin >> score;
        T += score;
    }
    cout << (S >= T ? S : T);
    return 0;
}
