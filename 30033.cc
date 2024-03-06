#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  int count = 0;
  for (int i = 0; i < N; ++i) {
    int B;
    cin >> B;
    if (A[i] <= B) {
      ++count;
    }
  }
  cout << count;
  return 0;
}
