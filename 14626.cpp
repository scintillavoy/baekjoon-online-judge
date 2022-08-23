#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    int sum = 0, asteriskPos;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '*') {
            asteriskPos = i;
        } else {
            sum += (str[i] - '0') * (i % 2 ? 3 : 1);
        }
    }
    int diff = 10 - sum % 10;
    if (diff == 10) {
        diff = 0;
    } else if (asteriskPos % 2) {
        while (diff % 3) {
            diff += 10;
        }
        diff /= 3;
    }
    cout << diff;
    return 0;
}
