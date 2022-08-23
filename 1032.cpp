#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> vec(N);
    for (auto &x : vec) {
        cin >> x;
    }
    for (int i = 0; i < vec.front().size(); ++i) {
        for (int j = 1; j < vec.size(); ++j) {
            if (vec.front()[i] != vec[j][i]) {
                vec.front()[i] = '?';
                break;
            }
        }
    }
    cout << vec.front();
    return 0;
}
