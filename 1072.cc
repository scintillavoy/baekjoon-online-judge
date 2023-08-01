#include <iostream>
using namespace std;

int main() {
  long long X, Y;
  cin >> X >> Y;
  int Z = 100 * Y / X;
  if (Z >= 99) {
    cout << -1;
    return 0;
  }
  int left = 1, right = X;
  while (left <= right) {
    int mid = (left + right) / 2;
    int new_Z = 100 * (Y + mid) / (X + mid);
    if (new_Z <= Z) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << left;
  return 0;
}
