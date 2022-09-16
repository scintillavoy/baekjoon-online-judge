#include <iostream>
#include <string>
using namespace std;

int main() {
  int sum = 0;
  string S;
  while (getline(cin, S, ',')) {
    sum += stoi(S);
  }
  cout << sum;
  return 0;
}
