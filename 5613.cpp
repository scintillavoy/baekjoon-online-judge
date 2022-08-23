#include <iostream>
using namespace std;

int main() {
    int result;
    cin >> result;
    while (true) {
        char op;
        int num;
        cin >> op;
        if (op == '=') {
            break;
        }
        cin >> num;
        switch (op) {
            case '+':
                result += num;
                break;
            case '-':
                result -= num;
                break;
            case '*':
                result *= num;
                break;
            case '/':
                result /= num;
                break;
        }
    }
    cout << result;
    return 0;
}
