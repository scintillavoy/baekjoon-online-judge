#include <iostream>
#include <string>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  string str;
  cin >> str;
  int left_count = 0, pair_count = 0;
  for (int i = 1; i < str.size(); ++i) {
    if (str[i - 1] == '(' && str[i] == '(') {
      ++left_count;
    } else if (str[i - 1] == ')' && str[i] == ')') {
      pair_count += left_count;
    }
  }
  cout << pair_count;
  return 0;
}
