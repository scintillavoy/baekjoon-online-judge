#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  while (N--) {
    string line;
    getline(cin, line);
    int max_depth = 0;
    int curr_depth = 0;
    for (const auto &x : line) {
      if (x == '[') {
        ++curr_depth;
      } else if (x == ']') {
        max_depth = max(max_depth, curr_depth);
        --curr_depth;
      }
    }
    cout << (1 << max_depth) << '\n';
  }
  return 0;
}
