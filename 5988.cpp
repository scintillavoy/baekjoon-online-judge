#include <iostream>
#include <cstdio>
#include <limits>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < N; ++i) {
        char prev, curr;
        while ((curr = getc(stdin)) != '\n') {
            prev = curr;
        }
        cout << (prev % 2 ? "odd" : "even") << '\n';
    }
    return 0;
}
