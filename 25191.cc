#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  int A, B;
  cin >> A >> B;
  cout << min(N, A / 2 + B);
  return 0;
}
