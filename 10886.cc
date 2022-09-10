#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int result = 0;
  while (N--) {
    bool is_cute;
    cin >> is_cute;
    if (is_cute) {
      ++result;
    } else {
      --result;
    }
  }
  cout << "Junhee is" << (result > 0 ? "" : " not") << " cute!";
  return 0;
}
