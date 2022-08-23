#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector< vector<char> > vec;
    for (int i = 0; i < N; ++i) {
        vector<char> vec2(N);
        for (int j = 0; j < N; ++j) {
            cin >> vec2[j];
        }
        vec.push_back(vec2);
    }
    int K;
    cin >> K;

    switch (K) {
        case 1:
            for (auto const &x : vec) {
                for (auto const &y : x) {
                    cout << y;
                }
                cout << '\n';
            }
            break;
        case 2:
            for (auto const &x : vec) {
                for (auto it = x.crbegin(); it != x.crend(); ++it) {
                    cout << *it;
                }
                cout << '\n';
            }
            break;
        case 3:
            for (auto it = vec.crbegin(); it != vec.crend(); ++it) {
                for (auto &x : *it) {
                    cout << x;
                }
                cout << '\n';
            }
            break;
    }
    return 0;
}
