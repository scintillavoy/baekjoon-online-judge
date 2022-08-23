#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

int main() {
    while (true) {
        int c, sum = 0;
        for (int i = 1; (c = getc(stdin)) != '\n'; ++i) {
            if (c == '#') {
                return 0;
            } else if (isupper(c)) {
                sum += (c - 'A' + 1) * i;
            }
        }
        cout << sum << '\n';
    }
}
