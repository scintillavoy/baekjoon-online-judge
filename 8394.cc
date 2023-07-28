#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int prev = 1, curr = 1;
  while (--n) {
    int temp = prev;
    prev = curr;
    curr = (curr + temp) % 10;
  }
  cout << curr;
  return 0;
}
