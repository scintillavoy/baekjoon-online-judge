#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int rows = sqrt(N), cols = sqrt(N);
  if (rows * cols < N) ++rows;
  if (rows * cols < N) ++cols;
  cout << rows << ' ' << cols;
  return 0;
}
