#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        vector<char> vec(M);
        for (auto &x : vec) {
            cin >> x;
        }
        for (auto it = vec.crbegin(); it != vec.crend(); ++it) {
            cout << *it;
        }
        cout << '\n';
    }
    return 0;
}
