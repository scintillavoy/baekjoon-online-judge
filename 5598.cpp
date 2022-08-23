#include <cstdio>
#include <cctype>
using namespace std;

int main() {
    int c;
    while ((c = getc(stdin)) != EOF) {
        if (isalpha(c)) {
            c -= 3;
            if (c < 'A') {
                c += 26;
            }
            putc(c, stdout);
        }
    }
    return 0;
}
