#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int A, B, C, D, E;
  cin >> A >> B >> C >> D >> E;
  int total_time = 0;
  if (A < 0) {
    total_time += -A * C + D;
    A = 0;
  }
  total_time += (B - A) * E;
  cout << total_time;
  return 0;
}
