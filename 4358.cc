#include <cmath>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  map<string, int> m;
  string input;
  int total_count = 0;
  while (getline(cin, input)) {
    ++m[input];
    ++total_count;
  }
  cout.precision(4);
  cout << fixed;
  for (const auto &x : m) {
    double ratio = (double)x.second / total_count * 100;
    ratio = round(ratio * pow(10, 4)) / pow(10, 4);
    cout << x.first << ' ' << ratio << '\n';
  }
  return 0;
}
