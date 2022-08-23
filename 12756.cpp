#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

int main() {
    pair<int, int> A, B;
    cin >> A.first >> A.second;
    cin >> B.first >> B.second;
    int cntA = ceil((double) A.second / B.first);
    int cntB = ceil((double) B.second / A.first);
    if (cntA > cntB) {
        cout << "PLAYER A";
    } else if (cntA < cntB) {
        cout << "PLAYER B";
    } else {
        cout << "DRAW";
    }
    return 0;
}
