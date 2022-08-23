#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  unordered_map<string, string> dict;

  int M;
  cin >> M;
  while (M--) {
    string word;
    cin >> word;
    string key;
    for (auto &x : word) {
      switch (x) {
        case 'A':
        case 'B':
        case 'C':
          key.push_back('2');
          break;
        case 'D':
        case 'E':
        case 'F':
          key.push_back('3');
          break;
        case 'G':
        case 'H':
        case 'I':
          key.push_back('4');
          break;
        case 'J':
        case 'K':
        case 'L':
          key.push_back('5');
          break;
        case 'M':
        case 'N':
        case 'O':
          key.push_back('6');
          break;
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
          key.push_back('7');
          break;
        case 'T':
        case 'U':
        case 'V':
          key.push_back('8');
          break;
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
          key.push_back('9');
          break;
      }
    }
    if (!dict.count(key)) {
      dict[key] = word;
    }
  }

  string result;
  string buffered_key;

  int N;
  cin >> N;
  while (N--) {
    int number;
    cin >> number;
    if (number == 1) {
      if (!buffered_key.empty()) {
        if (dict.count(buffered_key)) {
          result += dict[buffered_key];
        } else {
          result += string(buffered_key.length(), '*');
        }
        buffered_key.clear();
      }
      result.push_back(' ');
    } else {
      buffered_key.push_back(number + '0');
    }
  }
  if (!buffered_key.empty()) {
    if (dict.count(buffered_key)) {
      result += dict[buffered_key];
    } else {
      result += string(buffered_key.length(), '*');
    }
    buffered_key.clear();
  }

  cout << result;
  return 0;
}
