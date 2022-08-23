#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double arr[7][4] = {{9.23076, 26.7, 1.835, 1},
                        {1.84523, 75, 1.348, -1},
                        {56.0211, 1.5, 1.05, -1},
                        {4.99087, 42.5, 1.81, 1},
                        {0.188807, 210, 1.41, -1},
                        {15.9803, 3.8, 1.04, -1},
                        {0.11193, 254, 1.88, 1}};
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int score = 0;
        for (int j = 0; j < 7; ++j) {
            int P;
            cin >> P;
            score += arr[j][0] * pow((arr[j][1] - P)*arr[j][3], arr[j][2]);
        }
        cout << score << '\n';
    }
    return 0;
}
