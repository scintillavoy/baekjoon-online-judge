#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (auto &x : vec) {
      cin >> x;
    }

    int curr = 0;
    int k = 0;
    while (true) {
      if (curr + 1 == N) {
        cout << k << endl;
        break;
      }
      if (vec[curr] == -1) {
        cout << 0 << endl;
        break;
      }
      int next = vec[curr] - 1;
      vec[curr] = -1;
      curr = next;
      ++k;
    }
  }
  return 0;
}
