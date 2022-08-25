#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sum = 0;
  while (N--) {
    char number;
    cin >> number;
    sum += number - '0';
  }
  cout << sum;
  return 0;
}
