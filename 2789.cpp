#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    char c;
    while ((c = getc(stdin)) != '\n') {
        switch (c) {
            case 'C':
            case 'A':
            case 'M':
            case 'B':
            case 'R':
            case 'I':
            case 'D':
            case 'G':
            case 'E':
                break;
            default:
                cout << c;
                break;
        }
    }
    return 0;
}
