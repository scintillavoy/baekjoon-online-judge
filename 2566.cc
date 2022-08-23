#include <iostream>
#include <utility>
using namespace std;

int main() {
  int maxNum = -1;
  pair<int, int> maxIndex(-1, -1);
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      int num;
      cin >> num;
      if (num > maxNum) {
        maxNum = num;
        maxIndex = make_pair(i, j);
      }
    }
  }
  cout << maxNum << endl;
  cout << maxIndex.first + 1 << ' ' << maxIndex.second + 1 << endl;
  return 0;
}
