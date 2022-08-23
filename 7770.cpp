#include <iostream>
using namespace std;

int main() {
    int n;
    int level = 0, blocks = 1;
    for (cin >> n; n >= 0; n -= blocks) {
        blocks += level * 4;
        ++level;
    }
    cout << level - 1;
    return 0;
}
