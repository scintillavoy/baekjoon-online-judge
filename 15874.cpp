#include <cstdio>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int k, s;
    scanf("%d %d", &k, &s);
    getc(stdin);
    k %= 26;
    while (s--) {
        char c = getc(stdin);
        if (isupper(c)) {
            putc((c - 'A' + k) % 26 + 'A', stdout);
        } else if (islower(c)) {
            putc((c - 'a' + k) % 26 + 'a', stdout);
        } else {
            putc(c, stdout);
        }
    }
    putc('\n', stdout);
    return 0;
}
