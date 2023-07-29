#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  unordered_map<int, int> m;
  int N;
  cin >> N;
  while (N--) {
    int num;
    cin >> num;
    ++m[num];
  }
  int M;
  cin >> M;
  while (M--) {
    int num;
    cin >> num;
    cout << m[num] << ' ';
  }
  return 0;
}
