#include <iostream>
using namespace std;

bool win(char a, char b) {
    if ((a == 'R' && b == 'S') ||
        (a == 'S' && b == 'P') ||
        (a == 'P' && b == 'R')) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char in[4];
    for (auto &x : in) {
        cin >> x;
    }
    if ((win(in[0], in[2]) && win(in[0], in[3])) ||
        (win(in[1], in[2]) && win(in[1], in[3]))) {
        cout << "MS";
    } else if ((win(in[2], in[0]) && win(in[2], in[1])) ||
               (win(in[3], in[0]) && win(in[3], in[1]))) {
        cout << "TK";
    } else {
        cout << '?';
    }
    cout << '\n';
    return 0;
}
