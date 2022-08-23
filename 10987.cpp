#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int cnt = 0;
    while (true) {
        switch (getc(stdin)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++cnt;
                break;
            case EOF:
                cout << cnt;
                return 0;
        }
    }
}
