#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int k, d;
  cin >> k >> d;
  int answer = 1;
  while (k * ((int)pow(2, answer + 1) - 1) <= d) {
    ++answer;
  }
  cout << answer;
  return 0;
}
