#include <iostream>
using namespace std;

int main() {
    int P;
    cin >> P;
    cout.precision(2);
    while (P--) {
        int N;
        double D, A, B, F;
        cin >> N >> D >> A >> B >> F;
        cout << defaultfloat << N << ' ' << fixed << D / (A + B) * F << '\n';
    }
    return 0;
}
