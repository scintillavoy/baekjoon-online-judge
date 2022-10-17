#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int current = 1;
  while (N >= current) {
    N -= current;
    ++current;
    if (N < current) {
      cout << 0;
      return 0;
    }
    N -= current;
    ++current;
  }
  cout << current - N;
  return 0;
}
