#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    int cnt = 1;
    for (auto const &x : S) {
        if (x == ',') {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}
