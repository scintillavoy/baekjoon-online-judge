#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int count = n / 5;
  n %= 5;
  while (n % 2 != 0 && count > 0) {
    n += 5;
    --count;
  }
  count += n / 2;
  n %= 2;
  cout << (n == 0 ? count : -1);
  return 0;
}
