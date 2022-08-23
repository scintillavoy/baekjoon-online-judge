#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

int main() {
    int arr[26] = {0};
    int c;
    while ((c = getc(stdin)) != EOF) {
        if (islower(c)) {
            ++arr[c - 'a'];
        }
    }
    int maxElem = *max_element(arr, arr + 26);
    for (int i = 0; i < 26; ++i) {
        if (arr[i] == maxElem) {
            putc(i + 'a', stdout);
        }
    }
    return 0;
}
