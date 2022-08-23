#include <iostream>
using namespace std;

int main() {
    // input
    int arrA[10], arrB[10];
    for (auto &x : arrA) {
        cin >> x;
    }
    for (auto &x : arrB) {
        cin >> x;
    }

    // compute score
    int scoreA = 0, scoreB = 0, lastWinner = -1;
    for (int i = 0; i < 10; ++i) {
        if (arrA[i] > arrB[i]) {
            scoreA += 3;
            lastWinner = 0;
        } else if (arrA[i] < arrB[i]) {
            scoreB += 3;
            lastWinner = 1;
        } else {
            ++scoreA, ++scoreB;
        }
    }
    
    // output
    cout << scoreA << ' ' << scoreB << '\n';
    if (scoreA > scoreB) {
        cout << 'A';
    } else if (scoreA < scoreB) {
        cout << 'B';
    } else {
        switch (lastWinner) {
            case -1:
                cout << 'D';
                break;
            case 0:
                cout << 'A';
                break;
            case 1:
                cout << 'B';
                break;
        }
    }
    return 0;
}
