#include <iostream>
using namespace std;

int main() {
    long long T;
    cin >> T;
    while (T--) {
        long long num[3];
        char op[2];
        cin >> num[0] >> op[0] >> num[1] >> op[1] >> num[2];
        switch (op[0]) {
            case '+':
                cout << (num[0]+num[1] == num[2] ? "correct" : "wrong answer");
                break;
            case '-':
                cout << (num[0]-num[1] == num[2] ? "correct" : "wrong answer");
                break;
            case '*':
                cout << (num[0]*num[1] == num[2] ? "correct" : "wrong answer");
                break;
            case '/':
                cout << (num[0]/num[1] == num[2] ? "correct" : "wrong answer");
                break;
        }
        cout << '\n';
    }
    return 0;
}
