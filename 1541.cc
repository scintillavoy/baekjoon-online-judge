#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  cin >> input;
  bool should_subtract = false;
  string token;
  int answer = 0;
  int num;
  for (int i = 0; i < input.size(); ++i) {
    switch (input[i]) {
      case '-':
        num = stoi(token);
        token.clear();
        if (should_subtract) {
          num = -num;
        }
        answer += num;
        should_subtract = true;
        break;
      case '+':
        num = stoi(token);
        token.clear();
        if (should_subtract) {
          num = -num;
        }
        answer += num;
        break;
      default:
        token.push_back(input[i]);
        break;
    }
  }
  num = stoi(token);
  if (should_subtract) {
    num = -num;
  }
  answer += num;
  cout << answer;
  return 0;
}
