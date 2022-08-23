#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string cardNumber;
        cin >> cardNumber;
        int sum = 0;
        for (int i = 1; i < cardNumber.size(); i += 2) {
            sum += cardNumber[i] - '0';
        }
        for (int i = 0; i < cardNumber.size(); i += 2) {
            int num = (cardNumber[i] - '0') * 2;
            num = num / 10 + num % 10;
            sum += num;
        }
        cout << (sum % 10 ? 'F' : 'T') << '\n';
    }
    return 0;
}
