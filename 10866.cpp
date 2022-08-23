#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    deque<int> deq;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "push_front") {
            int num;
            cin >> num;
            deq.push_front(num);
        } else if (cmd == "push_back") {
            int num;
            cin >> num;
            deq.push_back(num);
        } else if (cmd == "pop_front") {
            if (deq.empty()) {
                cout << -1 << '\n';
            } else {
                cout << deq.front() << '\n';
                deq.pop_front();
            }
        } else if (cmd == "pop_back") {
            if (deq.empty()) {
                cout << -1 << '\n';
            } else {
                cout << deq.back() << '\n';
                deq.pop_back();
            }
        } else if (cmd == "size") {
            cout << deq.size() << '\n';
        } else if (cmd == "empty") {
            cout << (deq.empty() ? 1 : 0) << '\n';
        } else if (cmd == "front") {
            cout << (deq.empty() ? -1 : deq.front()) << '\n';
        } else if (cmd == "back") {
            cout << (deq.empty() ? -1 : deq.back()) << '\n';
        }
    }
    return 0;
}
