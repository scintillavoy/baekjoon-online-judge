#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int prev = 0, curr = 1;
  while (N--) {
    int temp = prev;
    prev = curr;
    curr = (curr + temp) % 15746;
  }
  cout << curr;
  return 0;
}
