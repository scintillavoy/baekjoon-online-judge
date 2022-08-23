#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int cnt = 0;
    char curr, prev = 'W';
    while (N--) {
        cin >> curr;
        if (prev == 'E' && curr == 'W') {
            ++cnt;
        }
        prev = curr;
    }
    cout << cnt;
    return 0;
}
