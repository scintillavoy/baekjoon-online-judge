#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long factorial = 1;
  for (int i = 2; i <= N; ++i) {
    factorial *= i;
  }
  cout << factorial;
  return 0;
}
