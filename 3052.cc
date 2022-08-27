#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  unordered_set<int> check;
  for (int i = 0; i < 10; ++i) {
    int number;
    cin >> number;
    check.insert(number % 42);
  }
  cout << check.size();
  return 0;
}
