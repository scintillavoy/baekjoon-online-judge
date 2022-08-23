#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
using namespace std;

int main() {
    int n;
    for (int i = 1; cin >> n; ++i) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!n) {
            break;
        }
        vector<string> vec(n);
        for (auto &x : vec) {
            getline(cin, x);
        }
        sort(vec.begin(), vec.end());
        cout << i << '\n';
        for (auto const &x : vec) {
            cout << x << '\n';
        }
    }
    return 0;
}
