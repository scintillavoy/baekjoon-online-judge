#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        int lower = 0, upper = 0, digit = 0, space = 0;
        for (auto const &x : str) {
            if (islower(x)) {
                ++lower;
            } else if (isupper(x)) {
                ++upper;
            } else if (isdigit(x)) {
                ++digit;
            } else if (isspace(x)) {
                ++space;
            }
        }
        cout << lower << ' ' << upper << ' ' << digit << ' ' << space << '\n';
    }
    return 0;
}
