#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  unordered_set<int> s;
  for (int i = 0; i < 5; ++i) {
    int num;
    cin >> num;
    if (s.count(num) == 0) {
      s.insert(num);
    } else {
      s.erase(num);
    }
  }
  cout << *s.begin();
  return 0;
}
