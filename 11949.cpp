#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (auto &x : A) {
        cin >> x;
    }
    for (int i = 1; i <= M; ++i) {
        for (int j = 0; j < A.size() - 1; ++j) {
            if (A[j] % i > A[j+1] % i) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    for (auto const &x : A) {
        cout << x << '\n';
    }
    return 0;
}
