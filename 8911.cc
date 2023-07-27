#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int T;
  cin >> T;
  int diff[5] = {0, 1, 0, -1, 0};
  while (T--) {
    int min_x = 0, max_x = 0, min_y = 0, max_y = 0;
    int curr_x = 0, curr_y = 0;
    int orientation = 0;
    string commands;
    cin >> commands;
    for (const auto &x : commands) {
      switch (x) {
        case 'F':
          curr_x += diff[orientation];
          curr_y += diff[orientation + 1];
          min_x = min(min_x, curr_x);
          max_x = max(max_x, curr_x);
          min_y = min(min_y, curr_y);
          max_y = max(max_y, curr_y);
          break;
        case 'B':
          curr_x -= diff[orientation];
          curr_y -= diff[orientation + 1];
          min_x = min(min_x, curr_x);
          max_x = max(max_x, curr_x);
          min_y = min(min_y, curr_y);
          max_y = max(max_y, curr_y);
          break;
        case 'L':
          orientation = (orientation + 1) % 4;
          break;
        case 'R':
          orientation = (orientation + 3) % 4;
          break;
      }
    }
    cout << (max_x - min_x) * (max_y - min_y) << '\n';
  }
  return 0;
}
