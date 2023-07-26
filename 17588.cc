#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int next_number = 1;
  bool is_good = true;
  while (n--) {
    int number;
    cin >> number;
    while (number > next_number) {
      cout << next_number << '\n';
      ++next_number;
      is_good = false;
    }
    ++next_number;
  }
  if (is_good) {
    cout << "good job";
  }
  return 0;
}
