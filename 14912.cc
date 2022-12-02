#include <iostream>
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  int count[10] = {0};
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j > 0; j /= 10) {
      ++count[j % 10];
    }
  }
  cout << count[d];
  return 0;
}
