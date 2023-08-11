#include <iostream>
using namespace std;

void print_hanoi(int level, int from, int to, int other) {
  if (level <= 0) return;
  print_hanoi(level - 1, from, other, to);
  cout << from << ' ' << to << '\n';
  print_hanoi(level - 1, other, to, from);
}

int main() {
  int N;
  cin >> N;
  cout << (1 << N) - 1 << '\n';
  print_hanoi(N, 1, 3, 2);
  return 0;
}
