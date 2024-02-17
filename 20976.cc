#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  vector<int> numbers(3);
  for (int i = 0; i < numbers.size(); ++i) {
    cin >> numbers[i];
  }
  sort(numbers.begin(), numbers.end());
  cout << numbers[1];
  return 0;
}
