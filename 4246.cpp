#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        if (!N) {
            break;
        }
        string str;
        cin >> str;
        vector<string> vec(N);
        for (int i = 0; i < str.size(); ++i) {
            vec[min(i % (N * 2), N * 2 - 1 - i % (N * 2))].push_back(str[i]);
        }
        for (auto const &x : vec) {
            cout << x;
        }
        cout << '\n';
    }
    return 0;
}
