#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  vector<int> vec(3);
  for (int i = 0; i < 3; ++i) {
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end());
  if (vec[0] == vec[1] && vec[1] == vec[2]) {
    cout << 2;
  } else if (vec[0] * vec[0] + vec[1] * vec[1] == vec[2] * vec[2]) {
    cout << 1;
  } else {
    cout << 0;
  }
  return 0;
}
