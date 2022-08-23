#include <cstdio>
using namespace std;

int main() {
    int cnt = 0;
    while (true) {
        switch (getc(stdin)) {
            case '#':
                return 0;
            case '\n':
                printf("%d\n", cnt);
                cnt = 0;
                break;
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                ++cnt;
            default:
                break;
        }
    }
}
