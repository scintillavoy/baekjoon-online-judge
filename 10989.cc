#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> vec(10001, 0);
  while (N--) {
    int number;
    cin >> number;
    ++vec[number];
  }
  for (int i = 1; i < vec.size(); ++i) {
    while (vec[i]--) {
      cout << i << '\n';
    }
  }
  return 0;
}
