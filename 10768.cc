#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int month, day;
  cin >> month >> day;
  if (month == 2 && day == 18) {
    cout << "Special";
  } else if (month < 2 || (month == 2 && day < 18)) {
    cout << "Before";
  } else {
    cout << "After";
  }
  return 0;
}
