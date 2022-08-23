#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<int> q;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "push") {
            int num;
            cin >> num;
            q.push(num);
        } else if (cmd == "pop") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (cmd == "size") {
            cout << q.size() << '\n';
        } else if (cmd == "empty") {
            cout << (q.empty() ? 1 : 0) << '\n';
        } else if (cmd == "front") {
            cout << (q.empty() ? -1 : q.front()) << '\n';
        } else if (cmd == "back") {
            cout << (q.empty() ? -1 : q.back()) << '\n';
        }
    }
    return 0;
}
