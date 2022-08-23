#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string input;
    stack<char> stk;
    int multiplier = 1, value = 0;
    cin >> input;

    for (auto it = input.cbegin(); it != input.cend(); ++it) {
        switch (*it) {
            case '(':
                stk.push(*it);
                multiplier *= 2;
                break;
            case '[':
                stk.push(*it);
                multiplier *= 3;
                break;
            case ')':
                if (stk.empty() || stk.top() != '(') {
                    cout << "0";
                    return 0;
                }
                stk.pop();
                if (it != input.cbegin() && *(it-1) == '(') {
                    value += multiplier;
                }
                multiplier /= 2;
                break;
            case ']':
                if (stk.empty() || stk.top() != '[') {
                    cout << "0";
                    return 0;
                }
                stk.pop();
                if (it != input.cbegin() && *(it-1) == '[') {
                    value += multiplier;
                }
                multiplier /= 3;
                break;
        }
    }

    if (!stk.empty()) {
        cout << "0";
    } else {
        cout << value;
    }
    return 0;
}
