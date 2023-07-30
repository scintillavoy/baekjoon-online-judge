#include <iostream>
#include <vector>
using namespace std;

int k;
vector<int> seq;

void solve(int n) {
  if (n == 0) {
    --k;
    if (k == 0) {
      cout << seq[0];
      for (int i = 1; i < seq.size(); ++i) {
        cout << '+' << seq[i];
      }
    }
    return;
  }
  for (int i = 1; i <= 3; ++i) {
    if (n < i) break;
    seq.push_back(i);
    solve(n - i);
    seq.pop_back();
  }
}

int main() {
  int n;
  cin >> n >> k;
  solve(n);
  if (k > 0) {
    cout << -1;
  }
  return 0;
}
