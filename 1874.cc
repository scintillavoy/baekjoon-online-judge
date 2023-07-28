#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  stack<int> s;
  string answer;
  int max_num = 0;
  while (n--) {
    int num;
    cin >> num;
    while (num > max_num) {
      ++max_num;
      s.push(max_num);
      answer.push_back('+');
    }
    if (s.top() == num) {
      s.pop();
      answer.push_back('-');
    } else {
      cout << "NO";
      return 0;
    }
  }
  for (const auto &x : answer) {
    cout << x << '\n';
  }
  return 0;
}
