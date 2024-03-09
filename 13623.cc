#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int A, B, C;
  cin >> A >> B >> C;
  int sum = A + B + C;
  switch (sum) {
    case 0:
    case 3:
      cout << '*';
      break;
    case 1:
    case 2:
      if (A == sum % 2) {
        cout << 'A';
      } else if (B == sum % 2) {
        cout << 'B';
      } else if (C == sum % 2) {
        cout << 'C';
      }
      break;
  }
  return 0;
}
