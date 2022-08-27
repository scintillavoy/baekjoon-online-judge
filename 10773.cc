#include <iostream>
#include <stack>
using namespace std;

int main() {
  int K;
  cin >> K;
  stack<int> stk;
  while (K--) {
    int number;
    cin >> number;
    if (number == 0) {
      stk.pop();
    } else {
      stk.push(number);
    }
  }
  int sum = 0;
  while (!stk.empty()) {
    sum += stk.top();
    stk.pop();
  }
  cout << sum;
  return 0;
}
