#include <iostream>
using namespace std;

int main() {
  long long N;
  cin >> N;
  cout << (N == 1 ? 0 : (N + 1) / 2);
  return 0;
}
