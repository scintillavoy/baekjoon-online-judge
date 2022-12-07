#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  const string symbols[] = {"Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex"};
  unordered_map<string, int> counts;
  for (const auto &symbol : symbols) {
    counts[symbol] = 0;
  }

  int total_count = 0;
  string symbol;
  while (cin >> symbol) {
    ++total_count;
    ++counts[symbol];
  }

  cout.precision(2);
  cout << fixed;
  for (const auto &symbol : symbols) {
    cout << symbol << ' ' << counts[symbol] << ' '
         << (double)counts[symbol] / total_count << '\n';
  }
  cout << "Total " << total_count << ' ' << (double)total_count / total_count
       << '\n';
  return 0;
}
