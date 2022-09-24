#include <forward_list>
#include <iostream>
#include <iterator>
using namespace std;

int main() {
  int N;
  cin >> N;
  forward_list<int> li;
  for (int i = N; i >= 1; --i) {
    li.push_front(i);
  }
  while (next(li.cbegin()) != li.cend()) {
    auto it = li.before_begin();
    while (true) {
      it = li.erase_after(it);
      if (it == li.end() || next(it) == li.end()) break;
    }
  }
  cout << li.front();
  return 0;
}
