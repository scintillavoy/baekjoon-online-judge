#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  const string names[9] = {"PROBRAIN", "GROW", "ARGOS", "ADMIN",   "ANT",
                           "MOTION",   "SPG",  "COMON", "ALMIGHTY"};
  int counts[9] = {0};
  for (auto &count : counts) {
    for (int j = 0; j < N; ++j) {
      int K;
      cin >> K;
      if (count < K) {
        count = K;
      }
    }
  }
  cout << names[max_element(counts, counts + 9) - counts];
  return 0;
}
