#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int k, w, m;
  cin >> k >> w >> m;
  if (k >= w) {
    cout << 0;
    return 0;
  }
  int answer = (w - k) / m;
  if ((w - k) % m != 0) {
    ++answer;
  }
  cout << answer;
  return 0;
}
