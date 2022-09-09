#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int arr[3];
  for (auto &x : arr) {
    cin >> x;
  }
  sort(arr, arr + 3);
  for (const auto &x : arr) {
    cout << x << ' ';
  }
  return 0;
}
