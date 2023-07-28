#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long prev = 2, curr = 2;
  while (N--) {
    long long temp = prev;
    prev = curr;
    curr += temp;
  }
  cout << curr;
  return 0;
}
