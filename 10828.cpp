#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<int> s;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "push") {
            int num;
            cin >> num;
            s.push(num);
        } else if (cmd == "pop") {
            if (s.empty()) {
                cout << -1 << '\n';
            } else {
                cout << s.top() << '\n';
                s.pop();
            }
        } else if (cmd == "size") {
            cout << s.size() << '\n';
        } else if (cmd == "empty") {
            cout << (s.empty() ? 1 : 0) << '\n';
        } else if (cmd == "top") {
            cout << (s.empty() ? -1 : s.top()) << '\n';
        }
    }
    return 0;
}
