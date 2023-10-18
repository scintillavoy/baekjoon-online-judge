#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int sum = 0;
  while (n--) {
    int number;
    cin >> number;
    sum += number;
  }
  if (sum > 0) {
    cout << "Right";
  } else if (sum < 0) {
    cout << "Left";
  } else {
    cout << "Stay";
  }
  return 0;
}
