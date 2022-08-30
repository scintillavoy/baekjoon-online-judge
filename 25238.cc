#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  cout << (a * (100 - b) < 10000 ? 1 : 0);
  return 0;
}
