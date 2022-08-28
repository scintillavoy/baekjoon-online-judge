#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string A, B;
  char op;
  cin >> A >> op >> B;
  switch (op) {
    case '+': {
      if (A.size() == B.size()) {
        cout << 2;
        for (int i = 1; i < A.size(); ++i) {
          cout << 0;
        }
      } else {
        int max_length = max(A.size(), B.size());
        int min_length = min(A.size(), B.size());
        cout << 1;
        for (int i = 1; i < max_length; ++i) {
          cout << (i == max_length - min_length ? 1 : 0);
        }
      }
      break;
    }
    case '*':
      cout << 1;
      for (int i = 0; i < A.size() + B.size() - 2; ++i) {
        cout << 0;
      }
      break;
  }
  return 0;
}
