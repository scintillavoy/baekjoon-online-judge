#include <cctype>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  bool digit = false, lowercase = false, uppercase = false, special = false;
  for (int i = 0; i < N; ++i) {
    char c;
    cin >> c;
    if (isdigit(c)) {
      digit = true;
    } else if (islower(c)) {
      lowercase = true;
    } else if (isupper(c)) {
      uppercase = true;
    } else {
      switch (c) {
        case '!':
        case '@':
        case '#':
        case '$':
        case '%':
        case '^':
        case '&':
        case '*':
        case '(':
        case ')':
        case '-':
        case '+':
          special = true;
      }
    }
  }
  int count = 0;
  if (!digit) ++count;
  if (!lowercase) ++count;
  if (!uppercase) ++count;
  if (!special) ++count;
  if (count < 6 - N) count = 6 - N;
  cout << count;
  return 0;
}
