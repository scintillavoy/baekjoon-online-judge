#include <iostream>
#include <string>
using namespace std;

int main() {
    int ball = 1;
    string str;
    cin >> str;
    for (auto const &x : str) {
        switch (x) {
            case 'A':
                if (ball == 1) {
                    ball = 2;
                } else if (ball == 2) {
                    ball = 1;
                }
                break;
            case 'B':
                if (ball == 2) {
                    ball = 3;
                } else if (ball == 3) {
                    ball = 2;
                }
                break;
            case 'C':
                if (ball == 1) {
                    ball = 3;
                } else if (ball == 3) {
                    ball = 1;
                }
                break;
        }
    }
    cout << ball;
    return 0;
}
