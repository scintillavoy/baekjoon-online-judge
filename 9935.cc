#include <iostream>
#include <string>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  string a, b;
  cin >> a >> b;
  string result;
  for (int i = 0; i < a.size(); ++i) {
    result.push_back(a[i]);
    if (a[i] != b.back() || result.size() < b.size()) {
      continue;
    }
    bool explodes = true;
    for (int j = 0; j < b.size(); ++j) {
      if (result[result.size() - b.size() + j] != b[j]) {
        explodes = false;
        break;
      }
    }
    if (explodes) {
      for (int j = 0; j < b.size(); ++j) {
        result.pop_back();
      }
    }
  }
  if (result.empty()) {
    result = "FRULA";
  }
  cout << result;
  return 0;
}
