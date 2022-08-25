#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  while (N--) {
    string sentence;
    getline(cin, sentence);
    vector<bool> check(26, false);
    for (const auto &x : sentence) {
      if (isalpha(x)) {
        check[tolower(x) - 'a'] = true;
      }
    }
    if (all_of(check.cbegin(), check.cend(), [](bool x) { return x; })) {
      cout << "pangram";
    } else {
      cout << "missing ";
      for (int i = 0; i < check.size(); ++i) {
        if (!check[i]) {
          cout << char(i + 'a');
        }
      }
    }
    cout << '\n';
  }
  return 0;
}
