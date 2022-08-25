#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  vector<int> position(26, -1);
  for (int i = 0; i < S.size(); ++i) {
    if (position[S[i] - 'a'] == -1) {
      position[S[i] - 'a'] = i;
    }
  }
  for (const auto &x : position) {
    cout << x << ' ';
  }
  return 0;
}
