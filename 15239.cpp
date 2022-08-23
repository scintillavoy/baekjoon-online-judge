#include <iostream>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int S;
        bool check[5] = {false};
        cin >> S;
        check[0] = S >= 12;
        while (S--) {
            char c;
            cin >> c;
            if (islower(c)) {
                check[1] = true;
            } else if (isupper(c)) {
                check[2] = true;
            } else if (isdigit(c)) {
                check[3] = true;
            } else if (strchr("+_)(*&^%$#@!./,;{}", c)) {
                check[4] = true;
            }
        }
        cout << (count(check, check + 5, false) == 0 ? "valid" : "invalid");
        cout << '\n';
    }
    return 0;
}
