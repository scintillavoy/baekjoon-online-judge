#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

bool is_prime(int n) {
  for (int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  string word;
  cin >> word;
  int sum = 0;
  for (const auto &c : word) {
    if (isupper(c)) {
      sum += c - 'A' + 27;
    } else {
      sum += c - 'a' + 1;
    }
  }
  cout << "It is ";
  if (!is_prime(sum)) {
    cout << "not ";
  }
  cout << "a prime word.";
  return 0;
}
