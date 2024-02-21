#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  int count = 0;
  for (int i = 0; i < N; ++i) {
    char c;
    int x;
    cin >> c >> c >> x;
    if (x <= 90) {
      ++count;
    }
  }
  cout << count;
  return 0;
}
