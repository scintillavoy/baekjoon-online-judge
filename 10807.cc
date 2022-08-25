#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> numbers(N);
  for (auto &x : numbers) {
    cin >> x;
  }
  int v;
  cin >> v;
  int count = 0;
  for (const auto &x : numbers) {
    if (x == v) ++count;
  }
  cout << count;
  return 0;
}
