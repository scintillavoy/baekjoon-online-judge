#include <iostream>
#include <set>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<int> numbers;
  while (N--) {
    int number;
    cin >> number;
    numbers.insert(number);
  }
  for (const auto &x : numbers) {
    cout << x << '\n';
  }
  return 0;
}
