#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  string password;
  cin >> password;
  if (password[0] == '0') {
    cout << 0;
    return 0;
  }
  vector<int> counts(password.size() + 1);
  counts[0] = 1;
  counts[1] = 1;
  for (int i = 1; i < password.size(); ++i) {
    if (password[i] != '0') {
      counts[i + 1] += counts[i];
    }
    if (password[i - 1] == '1' ||
        (password[i - 1] == '2' && password[i] <= '6')) {
      counts[i + 1] += counts[i - 1];
    }
    counts[i + 1] %= 1'000'000;
  }
  cout << counts.back();
  return 0;
}
