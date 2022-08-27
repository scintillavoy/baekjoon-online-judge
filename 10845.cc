#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  queue<int> q;
  while (N--) {
    string command;
    cin >> command;
    if (command == "push") {
      int number;
      cin >> number;
      q.push(number);
    } else if (command == "pop") {
      if (q.empty()) {
        cout << -1 << '\n';
      } else {
        cout << q.front() << '\n';
        q.pop();
      }
    } else if (command == "size") {
      cout << q.size() << '\n';
    } else if (command == "empty") {
      cout << (q.empty() ? 1 : 0) << '\n';
    } else if (command == "front") {
      cout << (q.empty() ? -1 : q.front()) << '\n';
    } else if (command == "back") {
      cout << (q.empty() ? -1 : q.back()) << '\n';
    }
  }
  return 0;
}
