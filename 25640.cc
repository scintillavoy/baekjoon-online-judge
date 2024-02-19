#include <iostream>
#include <string>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  string a;
  cin >> a;
  int N;
  cin >> N;
  int count = 0;
  for (int i = 0; i < N; ++i) {
    string b;
    cin >> b;
    if (a == b) {
      ++count;
    }
  }
  cout << count;
  return 0;
}
