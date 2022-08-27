#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  auto comp = [](const string &a, const string &b) {
    if (a.size() != b.size()) {
      return a.size() < b.size();
    } else {
      return a < b;
    }
  };
  set<string, decltype(comp)> s(comp);
  while (N--) {
    string word;
    cin >> word;
    s.insert(word);
  }
  for (const auto &x : s) {
    cout << x << '\n';
  }
  return 0;
}
