#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector< vector<int> > vec;
    for (int i = 0; i < N; ++i) {
        vector<int> vec2;
        for (int j = 0; j < M; ++j) {
            int num;
            cin >> num;
            vec2.push_back(num);
        }
        vec.push_back(vec2);
    }
    int K;
    cin >> K;
    for (int n = 0; n < K; ++n) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        int sum = 0;
        for (int k = i; k <= x; ++k) {
            for (int l = j; l <= y; ++l) {
                sum += vec[k-1][l-1];
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
