#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  --N;
  int distance;
  for (distance = 1; N > 0; ++distance) {
    N -= distance * 6;
  }
  cout << distance;
  return 0;
}
