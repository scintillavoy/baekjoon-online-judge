#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  stack<int> stk;
  while (N--) {
    string command;
    cin >> command;
    if (command == "push") {
      int number;
      cin >> number;
      stk.push(number);
    } else if (command == "pop") {
      if (stk.empty()) {
        cout << -1 << '\n';
      } else {
        cout << stk.top() << '\n';
        stk.pop();
      }
    } else if (command == "size") {
      cout << stk.size() << '\n';
    } else if (command == "empty") {
      cout << (stk.empty() ? 1 : 0) << '\n';
    } else if (command == "top") {
      cout << (stk.empty() ? -1 : stk.top()) << '\n';
    }
  }
  return 0;
}
