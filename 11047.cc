#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (auto &x : A) {
    cin >> x;
  }
  int count = 0;
  for (auto it = A.crbegin(); it != A.crend(); ++it) {
    count += K / *it;
    K %= *it;
  }
  cout << count;
  return 0;
}
