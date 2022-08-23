#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> vec;
    vec.reserve(N + 1);
    vec.push_back(0);
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        vec.push_back(num + vec.back());
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        cout << vec[b] - vec[a - 1] << '\n';
    }
    return 0;
}
