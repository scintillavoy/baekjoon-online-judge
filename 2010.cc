#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  int total_count = 1;
  for (int i = 0; i < N; ++i) {
    int count;
    cin >> count;
    total_count += count - 1;
  }
  cout << total_count;
  return 0;
}
