#include <iostream>
#include <string>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  string S;
  cin >> S;
  for (auto it = S.cend() - 5; it != S.cend(); ++it) {
    cout << *it;
  }
  return 0;
}
