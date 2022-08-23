#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        string first, last;
        cin >> first >> last;
        cout << "Case " << i << ": " << last << ", " << first << '\n';
    }
    return 0;
}
