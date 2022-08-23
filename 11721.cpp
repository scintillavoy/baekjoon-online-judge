#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    char buf[101];
    fgets(buf, sizeof buf, stdin);
    for (int i = 0; buf[i] != '\0'; ++i) {
        cout << buf[i];
        if (i % 10 == 9) {
            cout << '\n';
        }
    }
    return 0;
}
