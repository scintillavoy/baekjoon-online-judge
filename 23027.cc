#include <iostream>
#include <string>
using namespace std;

int main() {
  string letter;
  cin >> letter;
  bool check[3] = {false};
  for (const auto &x : letter) {
    switch (x) {
      case 'A':
      case 'B':
      case 'C':
        check[x - 'A'] = true;
    }
  }
  if (check[0]) {
    for (auto &x : letter) {
      switch (x) {
        case 'B':
        case 'C':
        case 'D':
        case 'F':
          x = 'A';
      }
    }
  } else if (check[1]) {
    for (auto &x : letter) {
      switch (x) {
        case 'C':
        case 'D':
        case 'F':
          x = 'B';
      }
    }
  } else if (check[2]) {
    for (auto &x : letter) {
      switch (x) {
        case 'D':
        case 'F':
          x = 'C';
      }
    }
  } else {
    letter = string(letter.size(), 'A');
  }
  cout << letter;
  return 0;
}
