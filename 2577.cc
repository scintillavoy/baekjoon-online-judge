#include <iostream>
#include <string>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  string product = to_string(A * B * C);
  int count[10] = {0};
  for (const auto &x : product) {
    ++count[x - '0'];
  }
  for (const auto &x : count) {
    cout << x << '\n';
  }
  return 0;
}
