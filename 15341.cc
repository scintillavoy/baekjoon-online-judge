#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string card_number;
  while (true) {
    getline(cin, card_number);
    if (card_number == "0000 0000 0000 0000") {
      break;
    }
    card_number.erase(remove(card_number.begin(), card_number.end(), ' '),
                      card_number.end());

    // Calculate sum
    int sum = 0;
    for (int i = 0; i < 8; ++i) {
      // Handle odd-labeled digits
      int value = (card_number[i * 2] - '0') * 2;
      if (value > 9) {
        value -= 9;
      }
      sum += value;

      // Handle even-labeled digits
      sum += card_number[i * 2 + 1] - '0';
    }

    // Print the result
    cout << (sum % 10 == 0 ? "Yes" : "No") << endl;
  }
  return 0;
}
