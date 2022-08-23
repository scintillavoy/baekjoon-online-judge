#include <cstdio>
using namespace std;

int main() {
    int c;
    putc(getc(stdin), stdout);
    while ((c = getc(stdin)) != '\n') {
        if (c == '-') {
            putc(getc(stdin), stdout);
        }
    }
    return 0;
}
