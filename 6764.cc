#include <iostream>
#include <vector>
using namespace std;

bool is_increasing(const vector<int> &v) {
  for (int i = 1; i < v.size(); ++i) {
    if (!(v[i - 1] < v[i])) {
      return false;
    }
  }
  return true;
}

bool is_decreasing(const vector<int> &v) {
  for (int i = 1; i < v.size(); ++i) {
    if (!(v[i - 1] > v[i])) {
      return false;
    }
  }
  return true;
}

bool is_identical(const vector<int> &v) {
  for (int i = 1; i < v.size(); ++i) {
    if (v[i - 1] != v[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  vector<int> depths(4);
  for (int i = 0; i < depths.size(); ++i) {
    cin >> depths[i];
  }
  if (is_increasing(depths)) {
    cout << "Fish Rising";
  } else if (is_decreasing(depths)) {
    cout << "Fish Diving";
  } else if (is_identical(depths)) {
    cout << "Fish At Constant Depth";
  } else {
    cout << "No Fish";
  }
  return 0;
}
