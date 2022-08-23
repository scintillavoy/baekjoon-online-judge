#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> vec(N, 0);
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        ++vec[A-1];
        ++vec[B-1];
    }
    for (auto const &x : vec) {
        cout << x << '\n';
    }
    return 0;
}
