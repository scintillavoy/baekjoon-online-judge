#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  string formula;
  cin >> formula;
  stack<int> stk;
  int sum = 0;
  for (const auto &x : formula) {
    switch (x) {
      case '(':
        stk.push(-1);
        break;
      case ')':
        while (true) {
          int current = stk.top();
          stk.pop();
          if (current == -1) {
            stk.push(sum);
            sum = 0;
            break;
          }
          sum += current;
        }
        break;
      case 'H':
        stk.push(1);
        break;
      case 'C':
        stk.push(12);
        break;
      case 'O':
        stk.push(16);
        break;
      default:
        stk.top() *= x - '0';
        break;
    }
  }
  sum = 0;
  while (!stk.empty()) {
    sum += stk.top();
    stk.pop();
  }
  cout << sum;
  return 0;
}
