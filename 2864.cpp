#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    string A2(A), B2(B);
    for (auto &x : A2) {
        if (x == '6') {
            x = '5';
        }
    }
    for (auto &x : B2) {
        if (x == '6') {
            x = '5';
        }
    }
    cout << stoi(A2) + stoi(B2);
    A2 = A;
    B2 = B;
    for (auto &x : A2) {
        if (x == '5') {
            x = '6';
        }
    }
    for (auto &x : B2) {
        if (x == '5') {
            x = '6';
        }
    }
    cout << ' ' << stoi(A2) + stoi(B2);
    return 0;
}
