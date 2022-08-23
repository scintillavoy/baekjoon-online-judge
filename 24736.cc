#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> points{6, 3, 2, 1, 2};
  int iteration = 2;
  while (iteration--) {
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
      int input;
      cin >> input;
      sum += input * points[i];
    }
    cout << sum << ' ';
  }
  return 0;
}
