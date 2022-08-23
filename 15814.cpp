#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main() {
    string S;
    int T;
    cin >> S >> T;
    for (int i = 0; i < T; ++i) {
        int A, B;
        cin >> A >> B;
        swap(S[A], S[B]);
    }
    cout << S;
    return 0;
}
