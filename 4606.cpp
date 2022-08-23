#include <cstdio>
using namespace std;

int main() {
    while (true) {
        char c;
        switch (c = getc(stdin)) {
            case ' ':
                printf("%%20");
                break;
            case '!':
                printf("%%21");
                break;
            case '$':
                printf("%%24");
                break;
            case '%':
                printf("%%25");
                break;
            case '(':
                printf("%%28");
                break;
            case ')':
                printf("%%29");
                break;
            case '*':
                printf("%%2a");
                break;
            case '#':
                return 0;
            default:
                printf("%c", c);
                break;
        }
    }
}
