#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> X(N);
  for (auto &x : X) {
    cin >> x;
  }
  sort(X.begin(), X.end());
  int num_of_students = 0;
  int num_of_teams = 0;
  for (int i = 0; i < X.size(); ++i) {
    if (num_of_students == 0) {
      ++num_of_teams;
      num_of_students = X[i];
    }
    --num_of_students;
  }
  cout << num_of_teams;
  return 0;
}
