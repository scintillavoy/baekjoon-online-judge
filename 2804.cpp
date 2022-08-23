#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    int idxA, idxB;
    for (idxA = 0; (idxB = B.find(A[idxA])) == string::npos; ++idxA);
    for (int i = 0; i < B.size(); ++i) {
        if (i == idxB) {
            cout << A;
        } else {
            for (int j = 0; j < idxA; ++j) {
                cout << '.';
            }
            cout << B[i];
            for (int j = 0; j < A.size() - idxA - 1; ++j) {
                cout << '.';
            }
        }
        cout << '\n';
    }
    return 0;
}
