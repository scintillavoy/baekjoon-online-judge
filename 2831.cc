#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> men_pos, men_neg, women_pos, women_neg;
  for (int i = 0; i < N; ++i) {
    int height;
    cin >> height;
    if (height > 0) {
      men_pos.push_back(height);
    } else {
      men_neg.push_back(height);
    }
  }
  for (int i = 0; i < N; ++i) {
    int height;
    cin >> height;
    if (height > 0) {
      women_pos.push_back(height);
    } else {
      women_neg.push_back(height);
    }
  }
  sort(men_pos.begin(), men_pos.end());
  sort(men_neg.begin(), men_neg.end(), greater<int>());
  sort(women_pos.begin(), women_pos.end());
  sort(women_neg.begin(), women_neg.end(), greater<int>());
  int count = 0;
  for (int i = 0, j = 0; i < men_pos.size() && j < women_neg.size();) {
    if (men_pos[i] < -women_neg[j]) {
      ++count;
      ++i;
    }
    ++j;
  }
  for (int i = 0, j = 0; i < women_pos.size() && j < men_neg.size();) {
    if (women_pos[i] < -men_neg[j]) {
      ++count;
      ++i;
    }
    ++j;
  }
  cout << count;
  return 0;
}
