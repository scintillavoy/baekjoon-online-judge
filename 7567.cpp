#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    char prev = 0, curr;
    int height = 0;
    while ((curr = getc(stdin)) != '\n') {
        if (curr == prev) {
            height += 5;
        } else {
            height += 10;
        }
        prev = curr;
    }
    cout << height;
    return 0;
}
