#include <deque>
#include <iostream>
#include <string>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
outer_loop:
  while (T--) {
    string p;
    cin >> p;
    int n;
    cin >> n;
    deque<int> dq(n);
    char c;
    cin >> c;
    for (int i = 0; i < n; ++i) {
      cin >> dq[i] >> c;
    }
    if (n == 0) {
      cin >> c;
    }
    bool is_reversed = false;
    for (const auto &x : p) {
      if (x == 'R') {
        is_reversed = !is_reversed;
      } else if (x == 'D') {
        if (dq.empty()) {
          cout << "error\n";
          goto outer_loop;
        }
        if (is_reversed) {
          dq.pop_back();
        } else {
          dq.pop_front();
        }
      }
    }
    cout << '[';
    if (!dq.empty()) {
      cout << (is_reversed ? dq.back() : dq.front());
    }
    for (int i = 1; i < dq.size(); ++i) {
      cout << ',' << (is_reversed ? dq[dq.size() - 1 - i] : dq[i]);
    }
    cout << "]\n";
  }
  return 0;
}
