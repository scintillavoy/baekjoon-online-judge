#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    cout.precision(1);
    cout << fixed << showpoint;
    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        int C_sum = 0;
        double GPA = 0;
        for (int j = 0; j < N; ++j) {
            int C;
            double G;
            cin >> C >> G;
            C_sum += C;
            GPA += C * G;
        }
        GPA /= C_sum;
        GPA = floor(GPA * 10 + 0.5) / 10;
        cout << C_sum << ' ' << GPA << '\n';
    }
    return 0;
}
