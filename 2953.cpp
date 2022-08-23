#include <iostream>
using namespace std;

int main() {
    int winner, score_max = 0;
    for (int i = 0; i < 5; ++i) {
        int score = 0, input;
        for (int j = 0; j < 4; ++j) {
            cin >> input;
            score += input;
        }
        if (score > score_max) {
            winner = i + 1;
            score_max = score;
        }
    }
    cout << winner << ' ' << score_max;
    return 0;
}
