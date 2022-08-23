#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int> index(26, -1);
    string S;
    cin >> S;
    for (auto it = S.crbegin(); it != S.crend(); ++it) {
        index[*it - 'a'] = S.crend() - it - 1;
    }
    // alternative way: S.find_first_of('a' + i) for i = 0 ~ 25
    for (auto const &x : index) {
        cout << x << ' ';
    }
    return 0;
}
