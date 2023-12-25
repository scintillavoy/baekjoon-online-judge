#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int L;
string alphabets;

bool is_valid(const string &password) {
  int num_of_vowels = 0;
  int num_of_consonants = 0;
  for (const auto &x : password) {
    switch (x) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        ++num_of_vowels;
        break;
      default:
        ++num_of_consonants;
    }
  }
  return num_of_vowels >= 1 && num_of_consonants >= 2;
}

void dfs(int curr, string password) {
  if (password.size() == L && is_valid(password)) {
    cout << password << '\n';
    return;
  }
  for (int next = curr + 1; next < alphabets.size(); ++next) {
    dfs(next, password + alphabets[next]);
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int C;
  cin >> L >> C;
  for (int i = 0; i < C; ++i) {
    char alphabet;
    cin >> alphabet;
    alphabets.push_back(alphabet);
  }
  sort(alphabets.begin(), alphabets.end());
  dfs(-1, "");
  return 0;
}
