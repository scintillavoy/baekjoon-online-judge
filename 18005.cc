#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n % 2 == 1) {
    cout << 0;
  } else if ((n / 2) % 2 == 1) {
    cout << 1;
  } else {
    cout << 2;
  }
  return 0;
}
