#include <functional>
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

int main() {
  int N, k;
  cin >> N >> k;
  multiset<int, greater<int>> scores;
  while (N--) {
    int x;
    cin >> x;
    scores.insert(x);
  }
  cout << *next(scores.cbegin(), k - 1);
  return 0;
}
