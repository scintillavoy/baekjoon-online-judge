#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string A, B;
  cin >> A >> B;
  vector<vector<int>> length(A.size() + 1, vector<int>(B.size() + 1));
  for (int i = 1; i <= A.size(); ++i) {
    for (int j = 1; j <= B.size(); ++j) {
      if (A[i - 1] == B[j - 1]) {
        length[i][j] = length[i - 1][j - 1] + 1;
      } else {
        length[i][j] = max(length[i - 1][j], length[i][j - 1]);
      }
    }
  }
  cout << length[A.size()][B.size()];
  return 0;
}
