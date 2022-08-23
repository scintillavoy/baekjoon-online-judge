#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    for (; n >= 5; n -= 5, ++cnt);
    for (; n % 3 && cnt; n += 5, --cnt);
    for (; n >= 3; n -= 3, ++cnt);
    cout << (n ? -1 : cnt);
    return 0;
}
