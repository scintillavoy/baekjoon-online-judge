#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long prev = 0, curr = 1;
  while (--n) {
    long long temp = prev;
    prev = curr;
    curr += temp;
  }
  cout << curr;
  return 0;
}
