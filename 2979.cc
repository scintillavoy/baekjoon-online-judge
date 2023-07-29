#include <iostream>
#include <vector>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  vector<int> vec(100);
  for (int i = 0; i < 3; ++i) {
    int from, to;
    cin >> from >> to;
    for (int j = from; j < to; ++j) {
      ++vec[j];
    }
  }
  int price = 0;
  for (int i = 1; i <= vec.size(); ++i) {
    if (vec[i] == 1) {
      price += A;
    } else if (vec[i] == 2) {
      price += 2 * B;
    } else if (vec[i] == 3) {
      price += 3 * C;
    }
  }
  cout << price;
  return 0;
}
