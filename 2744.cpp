#include <cstdio>
#include <cctype>
using namespace std;

int main() {
    int c;
    while ((c = getc(stdin)) != EOF) {
        if (isupper(c)) {
            putc(tolower(c), stdout);
        } else if (islower(c)) {
            putc(toupper(c), stdout);
        }
    }
    return 0;
}
