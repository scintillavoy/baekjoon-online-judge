#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;
    stack<char> stk;
    int cnt = 0;
    for (auto it = input.cbegin(); it != input.cend(); ++it) {
        switch (*it) {
            case '(':
                stk.push(*it);
                break;
            case ')':
                stk.pop();
                if (*(it-1) == '(') {
                    cnt += stk.size();
                } else {
                    ++cnt;
                }
                break;
        }
    }
    cout << cnt;
    return 0;
}
