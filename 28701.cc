#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sum = 0;
  for (int i = 1; i <= N; ++i) {
    sum += i;
  }
  cout << sum << '\n';
  cout << sum * sum << '\n';
  sum = 0;
  for (int i = 1; i <= N; ++i) {
    sum += i * i * i;
  }
  cout << sum << '\n';
  return 0;
}
