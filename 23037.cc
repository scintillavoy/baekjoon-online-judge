#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int result = 0;
  while (n > 0) {
    result += pow(n % 10, 5);
    n /= 10;
  }
  cout << result;
  return 0;
}
