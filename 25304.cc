#include <iostream>
using namespace std;

int main() {
  int X;
  cin >> X;
  int N;
  cin >> N;
  while (N--) {
    int a, b;
    cin >> a >> b;
    X -= a * b;
  }
  cout << (X == 0 ? "Yes" : "No");
  return 0;
}
