#include <iostream>
using namespace std;

int main() {
  int t1, e1, f1;
  cin >> t1 >> e1 >> f1;
  int t2, e2, f2;
  cin >> t2 >> e2 >> f2;
  int time1 = t1 * 3 + e1 * 20 + f1 * 120;
  int time2 = t2 * 3 + e2 * 20 + f2 * 120;
  if (time1 > time2) {
    cout << "Max";
  } else if (time1 < time2) {
    cout << "Mel";
  } else {
    cout << "Draw";
  }
  cout << '\n';
  return 0;
}
