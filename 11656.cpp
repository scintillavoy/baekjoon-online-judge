#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string S;
    cin >> S;
    vector<string> vec;
    for (int i = 0; i < S.size(); ++i) {
        vec.push_back(S.substr(i));
    }
    sort(vec.begin(), vec.end());
    for (auto const &x : vec) {
        cout << x << '\n';
    }
    return 0;
}
