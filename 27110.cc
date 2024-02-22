#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  int A, B, C;
  cin >> A >> B >> C;
  cout << min(N, A) + min(N, B) + min(N, C);
  return 0;
}
