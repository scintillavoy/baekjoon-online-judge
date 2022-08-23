#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int scoreA = 100, scoreB = 100;
    for (int i = 0; i < n; ++i) {
        int numA, numB;
        cin >> numA >> numB;
        if (numA > numB) {
            scoreB -= numA;
        } else if (numA < numB) {
            scoreA -= numB;
        }
    }
    cout << scoreA << '\n' << scoreB;
    return 0;
}
