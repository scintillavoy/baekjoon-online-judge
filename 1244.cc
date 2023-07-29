#include <iostream>
#include <vector>
using namespace std;

int main() {
  int num_of_switches;
  cin >> num_of_switches;
  vector<bool> switches(num_of_switches, false);
  cin >> noboolalpha;
  for (auto &&x : switches) {
    bool input;
    cin >> input;
    x = input;
  }
  int num_of_students;
  cin >> num_of_students;
  for (int i = 0; i < num_of_students; ++i) {
    int type, num;
    cin >> type >> num;
    if (type == 1) {
      for (int j = num - 1; j < switches.size(); j += num) {
        switches[j] = !switches[j];
      }
    } else if (type == 2) {
      int left = num - 1, right = num - 1;
      while (left - 1 >= 0 && right + 1 < switches.size() &&
             switches[left - 1] == switches[right + 1]) {
        --left;
        ++right;
      }
      for (int j = left; j <= right; ++j) {
        switches[j] = !switches[j];
      }
    }
  }
  cout << switches[0];
  for (int i = 1; i < switches.size(); ++i) {
    if (i % 20 == 0) {
      cout << '\n' << switches[i];
    } else {
      cout << ' ' << switches[i];
    }
  }
  return 0;
}
