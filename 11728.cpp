#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (auto &x : A) {
        cin >> x;
    }
    for (auto &x : B) {
        cin >> x;
    }
    int idxA = 0, idxB = 0;
    while (idxA < A.size() && idxB < B.size()) {
        if (A[idxA] < B[idxB]) {
            cout << A[idxA++] << ' ';
        } else {
            cout << B[idxB++] << ' ';
        }
    }
    for (int i = idxA; i < A.size(); ++i) {
        cout << A[idxA++] << ' ';
    }
    for (int i = idxB; i < B.size(); ++i) {
        cout << B[idxB++] << ' ';
    }
    return 0;
}
