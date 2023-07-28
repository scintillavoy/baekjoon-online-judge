#include <iostream>
#include <utility>
using namespace std;

int main() {
  int max_num = -1;
  pair<int, int> max_index(-1, -1);
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      int num;
      cin >> num;
      if (num > max_num) {
        max_num = num;
        max_index = make_pair(i, j);
      }
    }
  }
  cout << max_num << endl;
  cout << max_index.first + 1 << ' ' << max_index.second + 1 << endl;
  return 0;
}
