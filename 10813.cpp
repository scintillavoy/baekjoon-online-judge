#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> vec(N);
    for (int i = 0; i < N; ++i) {
        vec[i] = i + 1;
    }
    for (int i = 0; i < M; ++i) {
        int a, b, temp;
        cin >> a >> b;
        temp = vec[a - 1];
        vec[a - 1] = vec[b - 1];
        vec[b - 1] = temp;
    }
    for (auto const &x : vec) {
        cout << x << ' ';
    }
    return 0;
}
