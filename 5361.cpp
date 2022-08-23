#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    cout.precision(2);
    cout << fixed << showpoint;
    for (int i = 0; i < T; ++i) {
        int A, B, C, D, E;
        cin >> A >> B >> C >> D >> E;
        cout << '$';
        cout << A*350.34 + B*230.90 + C*190.55 + D*125.30 + E*180.90 << '\n';
    }
    return 0;
}
