#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int X = 0;
  while (N--) {
    int P;
    cin >> P;
    X += pow(P / 10, P % 10);
  }
  cout << X;
  return 0;
}
