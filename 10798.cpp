#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> vec(5);
    for (auto &x : vec) {
        cin >> x;
    }
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (i < vec[j].size()) {
                cout << vec[j][i];
            }
        }
    }
    return 0;
}
