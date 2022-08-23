#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int arr[26] = {0};
    string str;
    cin >> str;
    for (auto const &x : str) {
        ++arr[x - 'a'];
    }
    cin >> str;
    for (auto const &x : str) {
        --arr[x - 'a'];
    }
    int cnt = 0;
    for (auto const &x : arr) {
        cnt += abs(x);
    }
    cout << cnt;
    return 0;
}
