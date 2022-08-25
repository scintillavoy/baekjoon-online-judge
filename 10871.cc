#include <iostream>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  while (N--) {
    int number;
    cin >> number;
    if (number < X) cout << number << ' ';
  }
  return 0;
}
