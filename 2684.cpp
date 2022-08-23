#include <iostream>
#include <limits>
using namespace std;

int main() {
    int P;
    cin >> P;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < P; ++i) {
        int arr[8] = {0};
        char prev2 = getc(stdin), prev = getc(stdin), curr;
        while ((curr = getc(stdin)) != '\n') {
            int pos = 0;
            if (curr == 'H') {
                pos += 1;
            }
            if (prev == 'H') {
                pos += 2;
            }
            if (prev2 == 'H') {
                pos += 4;
            }
            ++arr[pos];
            prev2 = prev;
            prev = curr;
        }
        for (auto const &x : arr) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}
