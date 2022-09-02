#include <deque>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  deque<int> deq;
  while (N--) {
    string command;
    cin >> command;
    if (command == "push_front") {
      int number;
      cin >> number;
      deq.push_front(number);
    } else if (command == "push_back") {
      int number;
      cin >> number;
      deq.push_back(number);
    } else if (command == "pop_front") {
      if (deq.empty()) {
        cout << -1 << '\n';
      } else {
        cout << deq.front() << '\n';
        deq.pop_front();
      }
    } else if (command == "pop_back") {
      if (deq.empty()) {
        cout << -1 << '\n';
      } else {
        cout << deq.back() << '\n';
        deq.pop_back();
      }
    } else if (command == "size") {
      cout << deq.size() << '\n';
    } else if (command == "empty") {
      cout << (deq.empty() ? 1 : 0) << '\n';
    } else if (command == "front") {
      cout << (deq.empty() ? -1 : deq.front()) << '\n';
    } else if (command == "back") {
      cout << (deq.empty() ? -1 : deq.back()) << '\n';
    }
  }
  return 0;
}
