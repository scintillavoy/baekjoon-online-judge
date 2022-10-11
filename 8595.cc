#include <cctype>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long sum = 0;
  int hidden_number = 0;
  while (n--) {
    char c;
    cin >> c;
    if (isdigit(c)) {
      hidden_number = hidden_number * 10 + c - '0';
    } else {
      sum += hidden_number;
      hidden_number = 0;
    }
  }
  sum += hidden_number;
  cout << sum;
  return 0;
}
