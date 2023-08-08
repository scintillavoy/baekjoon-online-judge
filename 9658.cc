#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<bool> vec{false, false, true, false, true};
  for (int i = 5; i <= N; ++i) {
    vec.push_back(!(vec[i - 1] && vec[i - 3] && vec[i - 4]));
  }
  cout << (vec[N] ? "SK" : "CY");
  return 0;
}
