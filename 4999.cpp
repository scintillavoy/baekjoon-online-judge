#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int cnt1 = 0, cnt2 = 0;
    while (getc(stdin) != 'h') {
        ++cnt1;
    }
    getc(stdin);
    while (getc(stdin) != 'h') {
        ++cnt2;
    }
    cout << (cnt1 >= cnt2 ? "go" : "no");
    return 0;
}
