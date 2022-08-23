#include <iostream>
#include <cstdio>
#include <limits>
using namespace std;

int main() {
    int length, score = 0;
    cin >> length;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < length; ++i) {
        score += getc(stdin) - 'A' + 1;
    }
    cout << score;
    return 0;
}
