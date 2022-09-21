#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  vector<int> result;
  while (A > 0 || B > 0) {
    int a = 0, b = 0;
    if (A > 0) {
      a = A % 10;
      A /= 10;
    }
    if (B > 0) {
      b = B % 10;
      B /= 10;
    }
    result.push_back(a + b);
  }
  for (auto it = result.crbegin(); it != result.crend(); ++it) {
    cout << *it;
  }
  return 0;
}
