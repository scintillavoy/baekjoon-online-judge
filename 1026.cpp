#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (auto &x : A) {
        cin >> x;
    }
    for (auto &x : B) {
        cin >> x;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int S = 0;
    for (int i = 0; i < N; ++i) {
        S += A[i] * B[N - 1 - i];
    }
    cout << S;
    return 0;
}
